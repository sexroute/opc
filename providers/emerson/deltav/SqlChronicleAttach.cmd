
@if "%1%"=="" goto HELP
@if "%2%"=="" goto HELP

@echo SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "CREATE DATABASE [%1] ON ( FILENAME = N'%2' ) FOR ATTACH_REBUILD_LOG"
@SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "CREATE DATABASE [%1] ON ( FILENAME = N'%2' ) FOR ATTACH_REBUILD_LOG"
@echo -----

@echo SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "ALTER DATABASE [%1] SET AUTO_CLOSE OFF WITH NO_WAIT"
@SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "ALTER DATABASE [%1] SET AUTO_CLOSE OFF WITH NO_WAIT"
@echo -----

@goto END

:HELP
@echo Requires two parameters:
@echo   database name
@echo   file name

:END
