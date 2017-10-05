/***********************************************************************
*	COSC1254 - PROGRAMMING USING C++
*	SEMESTER 2 2017
*	ASSIGNMENT 2 - ENGLISH DRAUGHTS
*	NAME:		JOSHUA HANSEN
*	STUDENT NUMBER: S3589185
************************************************************************/
#include <iostream>

namespace player
{
	class player
	{
		std::string name;
		int id;

		public:
		player(std::string);
		std::string get_name();
		int get_id();
	};
}

