########################################################################
# C++ Programming
# Semester 2 2017 Assignment #2
# Full Name        : Adam Young & Joshua Hansen
# Student Number   : s3564209 & s3589185
########################################################################

CXX = g++

CXXFLAGS = -Wall -pedantic -std=c++14

OBJ =  model.o command.o controller.o add_player_window.o game_window.o main_menu.o  \
       menu.o player_selection_window.o ui.o window.o main_noncurses.o player.o token.o king.o normal.o

SOURCES=main_noncurses.cpp model.cpp game_window.cpp ui.cpp	\
	command.cpp main_menu.cpp window.cpp controller.cpp menu.cpp	\
	add_player_window.cpp player_selection_window.cpp

HEADERS=model.h game_window.h ui.h command.h main_menu.h window.h controller.h	\
       menu.h add_player_window.h player_selection_window.h

README=README.md

MAKEFILE=Makefile

PROG = game

BUILD = build

VPATH =  model/ ncview/ nc_controller/

main: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(PROG)

valgrind: $(OBJ)
	$(CXX) -g $(CXXFLAGS) $(OBJ) -o $(PROG)

clean:
	rm $(PROG) $(OBJ)
