@echo off
rem  ************************************************************
rem  **  Register all AMS ocx's and dll's                      **
rem  ************************************************************
regsvr32 /s AmsUIBlock_d.dll
regsvr32 /s AmsUIDevice_d.dll
regsvr32 /s AmsOleDll_d.dll

rem  ************************************************************
rem  **  Register all AMS executables                          **
rem  ************************************************************
AmsServer.exe /regserver

rem  ************************************************************
rem  **  Registers all standard AMS entities.                  **
rem  ************************************************************
regedit /s Ams.reg

rem  ************************************************************
rem  **  Register all AMS devices                              **
rem  ************************************************************
regedit /s ..\data\AmsDevices\001151\3051\3051T.reg
regedit /s ..\data\AmsDevices\001151\3244\3244.reg
regedit /s ..\data\AmsDevices\005100\0300\DVC5000fr5.reg

rem  ************************************************************
rem  **  Register AmsNtcSpecies dll                            **
rem  ************************************************************
regedit /s AmsNtcSpeciesA.reg
