@echo on
setlocal

SET MSBUILD="C:\Program Files (x86)\MSBuild\14.0\Bin\MSBuild.exe"
SET SOLUTION=%~dp0..\..\Dse.sln

%MSBUILD% %SOLUTION% /m /t:Build /p:Configuration=Debug
%MSBUILD% %SOLUTION% /m /t:Build /p:Configuration=Release

:EXIT
endlocal

pause
