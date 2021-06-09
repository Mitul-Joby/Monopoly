Monopoly: 
	gcc .\src\main.c .\src\game.c .\src\player.c -o Monopoly -w

clean: .\Monopoly.exe
	del /Q .\Monopoly.exe
