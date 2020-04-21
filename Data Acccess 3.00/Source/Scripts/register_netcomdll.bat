if not exist %1 goto END
if not exist "..\..\..\ConfigTool\bin\%2\Opc.ConfigTool.exe" goto END
"..\..\..\ConfigTool\bin\%2\Opc.ConfigTool.exe" -ra %1
"..\..\..\ConfigTool\bin\%2\Opc.ConfigTool.exe" -rx "%ProjectDir%\DefaultRegistration.xml"
:END