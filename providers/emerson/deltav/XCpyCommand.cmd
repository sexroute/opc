@if %1%=="" goto HELP
@if %2%=="" goto HELP
@if %3%=="" goto HELP

@echo on
@echo computername = %computername%
@echo userdomain = %userdomain%
@echo %%1%% = %1%
@echo %%2%% = %2%
@echo %%3%% = %3%
@echo -----

@echo XCopy
@echo @XCopy  %1  %2  /e /c /r /i /v /f /y  %3
@XCopy  %1  %2  /e /c /r /i /v /f /y  >>%3
@echo -----

goto END

:HELP
@echo Requires three paramenters:
@echo   source file or directory path (enclosed in quotes if embedded spaces)
@echo   destination file or directory path (enclosed in quotes if embedded spaces)
@echo   log directory + file path (enclosed in quotes if embedded spaces)

:END
