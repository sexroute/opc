[InstallShield Silent]
Version=v5.00.000
File=Response File
[File Transfer]
OverwriteReadOnly=NoToAll
[DlgOrder]
Dlg0=SdWelcome-0
Count=14
Dlg1=DlgMachine-0
Dlg2=DlgInstallMode-0
Dlg3=SdRegisterUser-0
Dlg4=SdLicense-0
Dlg5=DlgClientServer-0
Dlg6=DlgInstanceName-0
Dlg7=SetupTypeSQL-0
Dlg8=DlgServices-0
Dlg9=DlgSQLSecurity-0
Dlg10=DlgCollation-0
Dlg11=DlgServerNetwork-0
Dlg12=SdStartCopy-0
Dlg13=SdFinishReboot-0
[SdWelcome-0]
Result=1
[DlgMachine-0]
Type=1
Result=1
[DlgInstallMode-0]
Type=1
Result=1
[SdRegisterUser-0]
szName=frsi
Result=1
[SdLicense-0]
Result=1
[DlgClientServer-0]
Type=2
Result=1
[DlgInstanceName-0]
InstanceName=MSSQLSERVER
Result=1
[SetupTypeSQL-0]
szDir=%PROGRAMFILES%\Microsoft SQL Server
Result=301
szDataDir=%PROGRAMFILES%\Microsoft SQL Server
[DlgServices-0]
Local-Domain=3855
AutoStart=15
Result=1
[DlgSQLSecurity-0]
LoginMode=2
szPwd=' '
Result=1
[DlgCollation-0]
collation_name=SQL_Latin1_General_CP1_CI_AS
Result=1
[DlgServerNetwork-0]
NetworkLibs=255
TCPPort=1433
TCPPrxy=Default
NMPPipeName=\\.\pipe\sql\query
Result=1
[SdStartCopy-0]
Result=1
[License]
LicenseMode=PERDEVICE
LicenseLimit=50
[Application]
Name=Microsoft SQL Server
Version=8.00.000
Company=Microsoft
Lang=0009
[SdFinishReboot-0]
Result=1
BootOption=0
