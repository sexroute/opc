#! /usr/bin/env python
#coding=utf-8

from __future__ import absolute_import, division, print_function, unicode_literals

import os
import sys
import locale
import codecs
import string

CWD = os.path.dirname(__file__)

PKG_DIR = CWD
SRC_DIR = os.path.dirname(CWD)

ENCODING = locale.getpreferredencoding()

__ID__       = "Dse"

__VERSION__  = "1.0.0"
__REVISION__ = "*"

__SPEC__ = string.Template(r'''<?xml version="1.0" encoding="utf-8"?>
<package xmlns="http://schemas.microsoft.com/packaging/2011/08/nuspec.xsd">
  <metadata>
    <id>{id}</id>
    <version>{major}.{minor}.{patch}.{revision}</version>
    <title>FixComm Communication Library</title>
    <authors>Dong Jinqian</authors>
    <owners>BHXZ</owners>
    <requireLicenseAcceptance>false</requireLicenseAcceptance>
    <description>FixComm Communications Library</description>
    <summary>FixComm Communications Library</summary>
    <copyright>BHXZ Inc 2016</copyright>
    <dependencies>
      <dependency id="Ice" version="3.4.2" />
    </dependencies>
  </metadata>
  ${files}
</package>
''')

__DEBUG__ = r'''
  <files>
    <file src="..\bin\Debug\3.5\Dse.*" target="lib\net35" />
    <file src="..\bin\Debug\4.0\Dse.*" target="lib\net40" />
  </files>
'''

__RELEASE__ = r'''
  <files>
    <file src="..\bin\Obfuscated\3.5\Dse.*" target="lib\net35" />
    <file src="..\bin\Obfuscated\4.0\Dse.*" target="lib\net40" />
  </files>
'''

__BUILD__ = r'''@echo on
setlocal

SET MSBUILD="C:\Program Files (x86)\MSBuild\14.0\Bin\MSBuild.exe"
SET SOLUTION=%~dp0..\..\Dse.sln

%MSBUILD% %SOLUTION% /m /t:Build /p:Configuration=Debug
%MSBUILD% %SOLUTION% /m /t:Build /p:Configuration=Release

:EXIT
endlocal

pause
'''

__PACKAGE__ = string.Template(r'''@echo on
setlocal

:: CONFIG
SET CONFIGURATION=${config}

CALL %~dp0Version.bat

:: PATH
SET REPOSITORY=D:\Developer\Packages
SET PATH=D:\Applications\NET\NuGet;%PATH%

SET SOURCE=%REPOSITORY%\%CONFIGURATION%
SET OUTDIR=pkg\%CONFIGURATION%
if not exist %OUTDIR% mkdir %OUTDIR%
nuget pack %CONFIGURATION%.nuspec -OutputDirectory %OUTDIR% -Verbosity detailed
IF %ERRORLEVEL% NEQ 0 GOTO EXIT
nuget delete %PACKAGE% %VERSION% -Source %SOURCE% -NonInteractive -Verbosity detailed
nuget add %OUTDIR%\%PACKAGE%.%VERSION%.nupkg -Source %SOURCE% -Verbosity detailed

:EXIT
endlocal
''')



CTX = dict(
  id       = __ID__,
  version  = __VERSION__,
)

if any(i in __VERSION__ for i in ('-','+',)):
  import semver

  CTX.update(semver.parse(__VERSION__))
else:
  v = __VERSION__.split('.');

  CTX['major']    = v[0]
  CTX['minor']    = v[1] if len(v)>1 else 0
  CTX['patch']    = v[2] if len(v)>2 else 0

  if len(v) > 3:
    CTX['revision'] = v[3]

if 'revision' not in CTX:
  try:
    revision = __REVISION__
  except NameError:
    pass
  else:
    if revision:
      if revision == "*":
        import subprocess

        hg  = r"C:\Program Files\TortoiseHg\hg.exe"

        CTX['revision'] = subprocess.check_output([hg, "id", "-n"]).rstrip('+\n')
      else:
        CTX['revision'] = revision

class Template(object):

  def __init__(self, path, template, encoding='utf-8'):
    self.debug    = True

    self.path     = path
    self.template = template
    self.encoding = encoding

  def format(self, version):
    return self.template.format(**version)

  def update(self, context):
    with codecs.open(self.path, 'w', self.encoding) as fo:
      if self.debug:
        print('updating', self.path, '...')
      fo.write(self.format(context))

OUT = [
Template(
  path     = os.path.join(SRC_DIR, 'Version.cs'),
  encoding = ENCODING,
  template = \
u'''namespace Dse
{{
    class Version
    {{
        public const string Major       = "{major}";
        public const string Minor       = "{minor}";
        public const string Patch       = "{patch}";
        public const string Revision    = "{revision}";

        public const string AssemblyVersion = "{major}.{minor}.{patch}.0";
        public const string FileVersion = "{major}.{minor}.{patch}.{revision}";
    }}
}}
'''
),
Template(
  path     = os.path.join(PKG_DIR, 'Build.bat'),
  encoding = ENCODING,
  template = __BUILD__
),
Template(
  path     = os.path.join(PKG_DIR, 'Debug.nuspec'),
  template = __SPEC__.substitute(files=__DEBUG__.strip())
),
Template(
  path     = os.path.join(PKG_DIR, 'Release.nuspec'),
  template = __SPEC__.substitute(files=__RELEASE__.strip())
),
Template(
  path     = os.path.join(PKG_DIR, 'Version.bat'),
  encoding = ENCODING,
  template = \
'''@echo on
SET PACKAGE={id}
SET VERSION={major}.{minor}.{patch}.{revision}
'''
),
Template(
  path     = os.path.join(PKG_DIR, 'Debug.bat'),
  template = __PACKAGE__.substitute(config='Debug')
),
Template(
  path     = os.path.join(PKG_DIR, 'Release.bat'),
  template = __PACKAGE__.substitute(config='Release')
),
Template(
  path     = os.path.join(PKG_DIR, 'Publish.bat'),
  template = r'''@echo off
setlocal

CALL %~dp0Debug.bat
CALL %~dp0Release.bat

:EXIT
endlocal

pause
'''
),
]

def update_version():

  for o in OUT:
    o.update(CTX)


if __name__ == '__main__':
  update_version()

  sys.exit(0)
