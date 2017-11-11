/***********************************************************************
*	COSC1254 - PROGRAMMING USING C++
*	SEMESTER 2 2017
*	ASSIGNMENT 2 - ENGLISH DRAUGHTS
*	AUTHOURS:		JOSHUA HANSEN
*	STUDENT NUMBERS: S3589185
************************************************************************/
#include <vector>
#include <memory>
#include <utility>
#include <iostream>
#include <sstream>
#include <map>
#include <thread>
#include <chrono>

#pragma once

namespace player
{
        class player
        {
            static std::unique_ptr<player> instance;

	    std::string name;
	    int player_id;
	    int score;

            public:
	    player(void);
            void set_name(const std::string& );
	    void set_id(int);
	    int get_id(void);
            int get_player_score(void);
            std::string get_name(void);
	    void add_score(int);
            static player * get_instance(void);
            static void delete_instance(void);
            virtual ~player(void);
        };
}

