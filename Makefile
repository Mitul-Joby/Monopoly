Monopoly: obj .\obj\main.o .\obj\maingame.o .\obj\game.o .\obj\player.o
	gcc .\obj\main.o .\obj\maingame.o .\obj\game.o .\obj\player.o -o Monopoly
	@echo Make successful

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

clean: Monopoly
	del /Q Monopoly.exe
	del /Q .\obj
	RD .\obj	
# 	cls||clear
	@echo Clean successful
