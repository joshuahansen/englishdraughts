############################################
#	COSC1254 - PROGRAMMING USING C++
#	SEMESTER 2 2017
#	ASSIGNMENT 2 - ENGLISH DRAUGHTS
#	NAME:		JOSHUA HANSEN
#	STUDENT NUMBER: S3589185
############################################

CC = g++
CFLAGS = -Wall -pedantic -std=c++14
OBJ =  model.o command.o controller.o add_player_window.o game_window.o main_menu.o menu.o player_selection_window.o ui.o window.o main_noncurses.o player.o
PROG = draughts_game
VPATH = model/ ncview/ nc_controller/

main: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(PROG)

clean:
	rm $(PROG) $(OBJ)
