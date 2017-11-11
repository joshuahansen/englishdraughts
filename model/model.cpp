#include "model.h"

int draughts::model::model::width = WIDTH;
std::unique_ptr<draughts::model::model> draughts::model::model::instance =
nullptr;

draughts::model::model::model(void) 
{
}

draughts::model::model * draughts::model::model::get_instance(void)
{
    if(instance == nullptr)
    {
        instance = std::unique_ptr<model>(new model);	
    }
    return instance.get();    
}

int draughts::model::model::get_player_score(int playernum)
{
    return players[playernum - 1]->get_player_score();
}

void draughts::model::model::start_game(int plr1, int plr2)
{
    playerid[0] = plr1;
    playerid[1] = plr2;

    // loop through the board and fill board with initial pieces
    for (int j=0; j<WIDTH; j+=1)
    {
        for (int i=0; i<WIDTH; i+=1)
        {
            // top three rows
            if (j < 3)
                if (j % 2 == 0 ? i % 2 == 1 : i % 2 == 0) // every two columns, alternating start column
                    board[j][i] = std::make_unique<token::normal>(j,i, players[plr1-1]->get_id(), 'o', direction::DOWN);
                else
                    board[j][i] = nullptr;
            else if (j >= 3 && j < WIDTH-3)
                board[j][i] = nullptr;
            else // last three rows
                if (j % 2 == 0 ? i % 2 == 1 : i % 2 == 0) // every two columns, alternating start column
                    board[j][i] = std::make_unique<token::normal>(j,i, players[plr2-1]->get_id(), 'x', direction::UP);
                else
                    board[j][i] = nullptr;
	}
    }
    currplayer = playerid[0];
}

int draughts::model::model::get_winner()
{
	int player1_score = 0, player2_score = 0;

	player1_score = get_player_score(PLAYER_1);
	player2_score = get_player_score(PLAYER_2);

	if(player1_score < player2_score)
		return PLAYER_2;
	else if(player1_score > player2_score)
		return PLAYER_1;
	else
	    	return 0;
}

std::string draughts::model::model::get_player_name(int id)
{
	return players[id - 1]->get_name();
}

char draughts::model::model::get_token(int x ,int y)
{
	if(board[x-1][y-1] == nullptr)
		return ' ';
	else
		return board[x-1][y-1]->get_token_char();
}

/**
 * Loop through board and make sure a next move is possible
 * Returns true if a move is possible, false otherwise
 */
bool draughts::model::model::moves_possible(int playernum)
{
    for (int j=0; j<WIDTH; j+=1)
    {
        for (int i=0; i<WIDTH; i+=1)
        {
            if(board[j][i] == nullptr || board[j][i]->get_player() != playernum)
                continue;

            if (board[j][i]->can_move(board))
                return true;

        }
    }

    // no pieces can move
    return false;
    
}

void draughts::model::model::make_move(int playernum,
        int startx, int starty, int endx, int endy)
{
	char token_char;
	if(move_again)
	{
		if(startx == prev_token.first && starty == prev_token.second)
		{
			if(board[startx-1][starty-1]->valid_take_token(endx-1, endy-1, board))
			{
				std::cout << "Take Token" <<std::endl;
				remove_token(startx - 1, starty - 1, endx - 1, endy - 1);
				board[endx-1][endy-1] = std::move(board[startx-1][starty-1]);
				board[endx-1][endy-1]->set_coords(endx-1, endy-1);
				update_player_score(playernum);
				if(board[endx-1][endy-1]->become_king())
				{
					token_char = toupper(board[endx-1][endy-1]->get_token_char());
					board[endx-1][endy-1] = nullptr;
					board[endx-1][endy-1] = std::make_unique<token::king>
						(endx-1, endy-1, playernum, token_char, 
						 draughts::direction::BOTH);
				}
				if(board[endx-1][endy-1]->take_another_token(board))
				{
					move_again = true;
					prev_token = std::make_pair (endx, endy);
				}
				else
				{	
					move_again = false;
					currplayer == playerid[0] ? currplayer = playerid[1] : 							currplayer = playerid[0];
				}
			}
			else
				std::cout << "\033[1;31mInvalid move\033[0m" << std::endl;
		}
		else
			std::cout << "\033[1;31mInvalid move\033[0m" << std::endl;
	}
	else
	{
		if(board[startx-1][starty-1] != nullptr && 
				board[startx-1][starty-1]->get_player() == playernum)
		{
			if(board[startx-1][starty-1]->move_token(endx-1, endy-1, board))
			{
				std::cout << "Move token" << std::endl;
				board[endx-1][endy-1] = std::move(board[startx-1][starty-1]);
				board[endx-1][endy-1]->set_coords(endx-1, endy-1);
				if(board[endx-1][endy-1]->become_king())
				{
					token_char = toupper(board[endx-1][endy-1]->get_token_char());
					board[endx-1][endy-1] = nullptr;
					board[endx-1][endy-1] = std::make_unique<token::king>
						(endx-1, endy-1, playernum, token_char, 
						 draughts::direction::BOTH);
				}
				currplayer == playerid[0] ? currplayer = playerid[1] : 
						currplayer = playerid[0];
			}
			else if(board[startx-1][starty-1]->valid_take_token(endx-1, endy-1, board))
			{
				std::cout << "Take Token" <<std::endl;
				remove_token(startx - 1, starty - 1, endx - 1, endy - 1);
				board[endx-1][endy-1] = std::move(board[startx-1][starty-1]);
				board[endx-1][endy-1]->set_coords(endx-1, endy-1);
				update_player_score(playernum);
				if(board[endx-1][endy-1]->become_king())
				{
					token_char = toupper(board[endx-1][endy-1]->get_token_char());
					board[endx-1][endy-1] = nullptr;
					board[endx-1][endy-1] = std::make_unique<token::king>
						(endx-1, endy-1, playernum, token_char, 
						 draughts::direction::BOTH);
				}
				if(board[endx-1][endy-1]->take_another_token(board))
				{
					move_again = true;
					prev_token = std::make_pair (endx, endy);
				}
				else
				{	
					move_again = false;
					currplayer == playerid[0] ? currplayer = playerid[1] : 							currplayer = playerid[0];
                    // check if we can play further
                    if(!moves_possible(currplayer))
                        std::cout << "\033[1;31mNo further moves possible. Game Over.\033[0m" << std::endl;
				}
			}
			else
				std::cout << "\033[1;31mInvalid move\033[0m" << std::endl;
		}
		else
			std::cout << "\033[1;31mInvalid move\033[0m" << std::endl;
	}
}
void draughts::model::model::remove_token(int startx, int starty, int endx, int endy)
{
	if(board[startx][starty]->get_direct() == draughts::direction::UP)
	{
		if(starty - 2 == endy)
			board[startx-1][starty-1] = nullptr;
		else
			board[startx-1][starty+1] = nullptr;
	}
	else if(board[startx][starty]->get_direct() == draughts::direction::DOWN)
	{
		if(starty - 2 == endy)
			board[startx+1][starty-1] = nullptr;
		else
			board[startx+1][starty+1] = nullptr;
	}
	else
	{
		//top left
		if(startx - 2 == endx && starty - 2 == endy)
			board[startx-1][starty-1] = nullptr;
		//top right
		else if(startx - 2 == endx && starty + 2 == endy)
			board[startx-1][starty+1] = nullptr;
		//bottom left
		else if(startx + 2 == endx && starty - 2 == endy)
			board[startx+1][starty-1] = nullptr;
		//bottom right
		else
			board[startx+1][starty+1] = nullptr;
	}
}
void draughts::model::model::update_player_score(int playernum)
{
	for(size_t i = 0; i < players.size(); ++i)
	{
		if(players[i]->get_id() == playernum)
			players[i]->add_score(1);
	}
}
void draughts::model::model::add_player(const std::string& p)
{
	int new_id = 0;
	std::unique_ptr<player::player> new_player = std::make_unique<player::player>();
	new_player->set_name(p);
	new_player->set_id(players.size() + 1);
	new_id = new_player->get_id();
	players.push_back(std::move(new_player));


    if (nameslist == nullptr)
    {
        nameslist = std::unique_ptr<std::map<int, std::string>>(new std::map<int, std::string>);
        nameslist->insert( std::pair<int, std::string>(new_id, p));
    } else
    {
        nameslist->insert( std::pair<int, std::string>(new_id, p));
    }

}

bool draughts::model::model::player_exists(const std::string& pname)
{
    for(std::map<int,std::string>::iterator it=nameslist->begin(); it!=nameslist->end(); ++it)
        if (it->second == pname)
            return true;

    return false;
}

int draughts::model::model::get_current_player(void)
{
    return currplayer;
}

std::map<int, std::string> draughts::model::model::get_player_list(void) 
    const
{
    if (nameslist != nullptr)
    {
        return *nameslist;
    } else
    {
        std::map<int, std::string> nameslist;
        return nameslist;
    }
    
}

void draughts::model::model::delete_instance(void)
{
    instance.reset(nullptr);
}


int draughts::model::model::get_width()
{
    return width;
}

int draughts::model::model::get_height()
{
    return width; // square board??
}

draughts::model::model::~model(void)
{
}

