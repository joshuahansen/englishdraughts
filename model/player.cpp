/***********************************************************************
*	COSC1254 - PROGRAMMING USING C++
*	SEMESTER 2 2017
*	ASSIGNMENT 2 - ENGLISH DRAUGHTS
*	NAME:		JOSHUA HANSEN
*	STUDENT NUMBER: S3589185
************************************************************************/

#include "player.h"

/*constructor to set players name*/
player::player::player(std::string str)
{
	player::player::name = str;
}
/*Get players name*/
std::string player::player::get_name()
{
	return player::player::name;
}
/*Get player's id*/
int player::player::get_id()
{
	return player::player::id;
}

