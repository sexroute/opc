@echo off
setlocal

CALL %~dp0Debug.bat
CALL %~dp0Release.bat

:EXIT
endlocal

pause
