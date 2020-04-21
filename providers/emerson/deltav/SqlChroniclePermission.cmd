@if "%1%"=="" goto HELP

@echo on
@echo computername = %computername%
@echo userdomain = %userdomain%
@echo %%1%% = %1%
@echo -----

@echo CREATE LOGIN %1%\DeltaV
@echo @SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "CREATE LOGIN [%1%\DeltaV] FROM WINDOWS WITH DEFAULT_DATABASE=[master]"
@SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "CREATE LOGIN [%1%\DeltaV] FROM WINDOWS WITH DEFAULT_DATABASE=[master]"
@echo -----

@echo CREATE LOGIN %1%\DeltaV Admins
@echo @SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "CREATE LOGIN [%1%\DeltaV Admins] FROM WINDOWS WITH DEFAULT_DATABASE=[master]"
@SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "CREATE LOGIN [%1%\DeltaV Admins] FROM WINDOWS WITH DEFAULT_DATABASE=[master]"
@echo -----

@@echo CREATE LOGIN %1%\DVECAdmin
@echo @SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "CREATE LOGIN [%1%\DVECAdmin] FROM WINDOWS WITH DEFAULT_DATABASE=[master]"
@SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "CREATE LOGIN [%1%\DVECAdmin] FROM WINDOWS WITH DEFAULT_DATABASE=[master]"
@echo -----


echo Add Role bulkadmin to 'DeltaV Admins'
@echo @SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DeltaV Admins', N'bulkadmin'"
@SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DeltaV Admins', N'bulkadmin'"
@echo -----

@echo Add Role dbcreator to 'DeltaV Admins'
@echo @SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DeltaV Admins', N'dbcreator'"
@SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DeltaV Admins', N'dbcreator'"
@echo -----

@echo Add Role diskadmin to 'DeltaV Admins'
@echo @SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DeltaV Admins', N'diskadmin'"
@SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DeltaV Admins', N'diskadmin'"
@echo -----

@echo Add Role processadmin to 'DeltaV Admins'
@echo @SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DeltaV Admins', N'processadmin'"
@SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DeltaV Admins', N'processadmin'"
@echo -----

@echo Add Role securityadmin to 'DeltaV Admins'
@echo @SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DeltaV Admins', N'securityadmin'"
@SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DeltaV Admins', N'securityadmin'"
@echo -----

@echo Add Role serveradmin to 'DeltaV Admins'
@echo @SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DeltaV Admins', N'serveradmin'"
@SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DeltaV Admins', N'serveradmin'"
@echo -----

@echo Add Role setupadmin to 'DeltaV Admins'
@echo @SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DeltaV Admins', N'setupadmin'"
@SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DeltaV Admins', N'setupadmin'"
@echo -----

@echo Add Role sysadmin to 'DeltaV Admins'
@echo @SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DeltaV Admins', N'sysadmin'"
@SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DeltaV Admins', N'sysadmin'"
@echo -----


echo Add Role bulkadmin to 'DVECAdmin'
@echo @SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DVECAdmin', N'bulkadmin'"
@SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DVECAdmin', N'bulkadmin'"
@echo -----

@echo Add Role dbcreator to 'DVECAdmin'
@echo @SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DVECAdmin', N'dbcreator'"
@SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DVECAdmin', N'dbcreator'"
@echo -----

@echo Add Role diskadmin to 'DVECAdmin'
@echo @SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DVECAdmin', N'diskadmin'"
@SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DVECAdmin', N'diskadmin'"
@echo -----

@echo Add Role processadmin to 'DVECAdmin'
@echo @SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DVECAdmin', N'processadmin'"
@SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DVECAdmin', N'processadmin'"
@echo -----

@echo Add Role securityadmin to 'DVECAdmin'
@echo @SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DVECAdmin', N'securityadmin'"
@SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DVECAdmin', N'securityadmin'"
@echo -----

@echo Add Role serveradmin to 'DVECAdmin'
@echo @SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DVECAdmin', N'serveradmin'"
@SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DVECAdmin', N'serveradmin'"
@echo -----

@echo Add Role setupadmin to 'DVECAdmin'
@echo @SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DVECAdmin', N'setupadmin'"
@SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DVECAdmin', N'setupadmin'"
@echo -----

@echo Add Role sysadmin to 'DVECAdmin'
@echo @SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DVECAdmin', N'sysadmin'"
@SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "EXEC sp_addsrvrolemember N'%1%\DVECAdmin', N'sysadmin'"
@echo -----


@echo GRANT VIEW ANY DATABASE
@echo @SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "GRANT VIEW ANY DATABASE TO [%1%\DeltaV] WITH GRANT OPTION"
@SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "GRANT VIEW ANY DATABASE TO [%1%\DeltaV] WITH GRANT OPTION"
@echo -----

@echo GRANT VIEW ANY DEFINITION
@echo @SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "GRANT VIEW ANY DEFINITION TO [%1%\DeltaV] WITH GRANT OPTION"
@SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "GRANT VIEW ANY DEFINITION TO [%1%\DeltaV] WITH GRANT OPTION"
@echo -----

@echo GRANT VIEW SERVER STATE
@echo @SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "GRANT VIEW SERVER STATE TO [%1%\DeltaV] WITH GRANT OPTION"
@SQLCMD -S %computername%\DELTAV_CHRONICLE -d master -Q "GRANT VIEW SERVER STATE TO [%1%\DeltaV] WITH GRANT OPTION"
@echo -----

goto END

:HELP
@echo Requires one paramenter:
@echo   the configured domain, if Domain Controller
@echo   %%COMPUTERNAME%%, otherwise

:END
