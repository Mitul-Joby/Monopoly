Monopoly: 
	gcc .\src\main.c .\src\game.c .\src\player.c -o Monopoly -w

uninstall: .\Monopoly.exe
	ERASE .\Monopoly.exe