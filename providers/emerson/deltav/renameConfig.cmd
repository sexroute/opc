@ECHO OFF

REM Post-installation reboot command file to be run one time.


IF "%1"=="" GOTO ERROR
IF "%2"=="" GOTO ERROR

ECHO.
ECHO Registering OCX's with the system...
ECHO.
%2\bin\regsvr32 /s %2\bin\diagram.ocx
%2\bin\regsvr32 /s %2\bin\VCF132.ocx

ECHO.
ECHO Registering PlugPlay and IVW with the system...
ECHO.

regedit /s %2\bin\FRSPPS.reg %2\bin\ivw.reg

pushd %2\fdb
ooinstal -lockserverhost %1 -fdfilehost %1 -fdfilepath %2\fdb\configdb.hdb.fdb -jnldirhost %1 -jnldirpath %2\fdb configdb.hdb
popd
ECHO.

:EXIT
GOTO SKIPERR

:ERROR
ECHO.
ECHO This command file registers the ocx's and renames the database.
ECHO The two parameters are "tcp\ip name" and the full path to where Hawk
ECHO is installed.
ECHO For example:
ECHO renameConfig wren d:\Hawk\code
ECHO.

:SKIPERR

pause

