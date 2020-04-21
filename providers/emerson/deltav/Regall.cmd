@echo off
date /t >%DeltaVRoot%\regall.log
time /t >>%DeltaVRoot%\regall.log
@echo Regall launched after DeltaV Installation.>>%DeltaVRoot%\regall.log
@echo on
@echo !!!!! PLEASE WAIT FOR REGALL TO COMPLETE !!!!! 
WaitForServiceToStart FIX
regall.exe /_register >>%DeltaVRoot%\regall.log
