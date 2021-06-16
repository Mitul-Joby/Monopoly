Monopoly: main.o game.o player.o
	gcc main.o game.o player.o -o Monopoly

main.o: .\src\main.c
	gcc -c .\src\main.c 
	
game.o: .\src\game.c
	gcc -c .\src\game.c 
	
player.o: .\src\player.c
	gcc -c .\src\player.c 

clean: .\Monopoly.exe
	del /Q .\Monopoly.exe
	del /Q *.o
