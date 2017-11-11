#include <vector>
#include <memory>
#include <utility>
#include <iostream>
#include <sstream>
#include <map>
#include <thread>
#include <chrono>
#include "token.h"

#pragma once

const int WIDTH = 8;
const int PLAYERS = 2;
const int PLAYER_1 = 1, PLAYER_2 = 2;

namespace draughts
{
    namespace model
    {
        class model
        {
            static std::unique_ptr<model> instance;
            static int width;
            std::unique_ptr<std::map<int, std::string>> nameslist;
            int playerid[PLAYERS];
	    std::vector<std::unique_ptr<player::player>> players;
	    std::unique_ptr<token::token> board[WIDTH][WIDTH];
	    bool move_again = false;
	    std::pair<int,int> prev_token;
            int currplayer;

            model(void);
            bool player_exists(const std::string&);

            public:
            void start_game(int, int);
            char get_token(int,int);
            bool moves_possible(int playernum);
            void make_move(int, int, int, int, int);
	    void update_player_score(int);
	    void remove_token(int,int,int,int);

            void add_player(const std::string& );
            int get_player_score(int);
            int get_current_player(void);
            std::string get_player_name(int);
            std::map<int, std::string> get_player_list(void) const;
            int get_winner();
            int get_width();
            int get_height();
            static model * get_instance(void);
            static void delete_instance(void);
            virtual ~model(void);
        };
    }
}
