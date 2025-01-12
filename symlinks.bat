:: Server Release
call :MKLINK "D:\topnet\server\ServerSide\AccountServer\AccountServer.exe" "D:\topnet\sources\Server\AccountServer\Bin\AccountServer.exe"
call :MKLINK "D:\topnet\server\ServerSide\AccountServer\AccountServer.pdb" "D:\topnet\sources\Server\AccountServer\Bin\AccountServer.pdb"
call :MKLINK "D:\topnet\server\ServerSide\GroupServer\GroupServer.exe" "D:\topnet\sources\Server\GroupServer\Bin\GroupServer.exe"
call :MKLINK "D:\topnet\server\ServerSide\GroupServer\GroupServer.pdb" "D:\topnet\sources\Server\GroupServer\Bin\GroupServer.pdb"
call :MKLINK "D:\topnet\server\ServerSide\GateServer\GateServer.exe" "D:\topnet\sources\Server\GateServer\Bin\GateServer.exe"
call :MKLINK "D:\topnet\server\ServerSide\GateServer\GateServer.pdb" "D:\topnet\sources\Server\GateServer\Bin\GateServer.pdb"
call :MKLINK "D:\topnet\server\ServerSide\GameServer\GameServer.exe" "D:\topnet\sources\Server\GameServer\Bin\GameServer.exe"
call :MKLINK "D:\topnet\server\ServerSide\GameServer\GameServer.pdb" "D:\topnet\sources\Server\GameServer\Bin\GameServer.pdb"

:: Client Release
call :MKLINK "D:\topnet\client\system\Game.exe" "D:\topnet\sources\Client\bin\system\Game.exe"
call :MKLINK "D:\topnet\client\system\Game.pdb" "D:\topnet\sources\Client\bin\system\Game.pdb"
call :MKLINK "D:\topnet\client\system\MindPower3D_D8R.dll" "D:\topnet\sources\Engine\lib\MindPower3D_D8R.dll"
call :MKLINK "D:\topnet\client\system\MindPower3D_D8R.pdb" "D:\topnet\sources\Engine\lib\MindPower3D_D8R.pdb"

pause

:MKLINK
if exist "%~1" del /F /Q "%~1"
mklink "%~1" "%~2"
EXIT/B 0