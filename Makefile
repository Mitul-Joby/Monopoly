ifdef OS
   RM = del /Q
else
   	ifeq ($(shell uname), Linux)
    	RM = rm -f
	endif
endif

Monopoly: 
	gcc .\src\main.c .\src\game.c .\src\player.c -o Monopoly -w

clean: .\Monopoly.exe
	$(RM) .\Monopoly.exe
