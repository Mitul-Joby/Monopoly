# Usage:
# make           # Compile Monopoly executable along with object files
# make Monopoly  # Compile only Monopoly executable
# make clean     # Removes all binaries and objects

.PHONY = all clean Monopoly
CC := gcc
SRCS := $(wildcard ./src/*.c)

ifeq ($(OS), Windows_NT)
RM := del /Q
RMOFILES := del /Q ./obj/*.o
else
RM := rm
RMOFILES := rm obj/*.o
endif

all: OFiles
	${CC} ./obj/definitions.o ./obj/main.o ./obj/maingame.o ./obj/game.o ./obj/player.o ./obj/sysSpecific.o -o Monopoly
	@echo Make successful

Monopoly: ${SRCS}
	${CC} ${SRCS} -o Monopoly
	@echo Compiled Monopoly successfully

OFiles: ./obj/definitions.o ./obj/main.o ./obj/maingame.o ./obj/game.o ./obj/player.o ./obj/sysSpecific.o
	@echo Files compiled successfully

./obj/definitions.o:./src/definitions.c
	${CC} -c ./src/definitions.c -o ./obj/definitions.o

./obj/main.o: ./src/main.c
	${CC} -c ./src/main.c -o ./obj/main.o

./obj/maingame.o: ./src/maingame.c
	${CC} -c ./src/maingame.c -o ./obj/maingame.o
	
./obj/game.o: ./src/game.c
	${CC} -c ./src/game.c -o ./obj/game.o
	
./obj/player.o: ./src/player.c
	${CC} -c ./src/player.c -o ./obj/player.o

./obj/sysSpecific.o: ./src/sysSpecific.c
	${CC} -c ./src/sysSpecific.c -o ./obj/sysSpecific.o

clean: all
	$(RM) Monopoly*
	$(RMOFILES)
	@echo Clean successful
