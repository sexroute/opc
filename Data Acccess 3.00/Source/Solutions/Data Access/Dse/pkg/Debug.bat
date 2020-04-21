@echo on
setlocal

:: CONFIG
SET CONFIGURATION=Debug

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
