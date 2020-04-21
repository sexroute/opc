@echo on
setlocal

SET CONFUSER="D:\Applications\NET\ConfuserEx_1.0.0\Confuser.CLI.exe"

%CONFUSER% -n %~dp0Dse35.crproj
%CONFUSER% -n %~dp0Dse40.crproj

:EXIT
endlocal

pause
