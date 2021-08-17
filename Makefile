all: OFiles
	gcc .\obj\main.o .\obj\maingame.o .\obj\game.o .\obj\player.o -o Monopoly
	@echo Make successful

Monopoly: .\src\main.c .\src\maingame.c .\src\game.c .\src\player.c
	gcc .\src\main.c .\src\maingame.c .\src\game.c .\src\player.c -o Monopoly
	@echo Compiled Monopoly successfully

OFiles: obj .\obj\main.o .\obj\maingame.o .\obj\game.o .\obj\player.o
	@echo Files compiled successfully

obj:
	MKDIR obj

.\obj\main.o: .\src\main.c
	gcc -c .\src\main.c -o .\obj\main.o

.\obj\maingame.o: .\src\maingame.c
	gcc -c .\src\maingame.c -o .\obj\maingame.o
	
.\obj\game.o: .\src\game.c
	gcc -c .\src\game.c -o .\obj\game.o
	
.\obj\player.o: .\src\player.c
	gcc -c .\src\player.c -o .\obj\player.o

clean: all
	del /Q Monopoly.exe
	del /Q .\obj
	RD .\obj	
# 	cls||clear
	@echo Clean successful
