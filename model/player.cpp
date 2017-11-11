/***********************************************************************
*	COSC1254 - PROGRAMMING USING C++
*	SEMESTER 2 2017
*	ASSIGNMENT 2 - ENGLISH DRAUGHTS
*	AUTHOURS:		JOSHUA HANSEN, ADAM YOUNG
*	STUDENT NUMBERS: S3589185 S3564209
************************************************************************/
#include "player.h"

/*std::unique_ptr<std::string> player::player::name = nullptr;*/
std::unique_ptr<player::player> player::player::instance = nullptr;

player::player::player(void)
{
	score = 0;
}

player::player * player::player::get_instance(void)
{
    if(instance == nullptr)
    {
        instance = std::unique_ptr<player>(new player);	
    }
    return instance.get();    
}

int player::player::get_player_score(void)
{
    return score;
}

void player::player::set_name(const std::string& p)
{
	name = p;
}

void player::player::delete_instance(void)
{
    instance.reset(nullptr);
}

std::string player::player::get_name(void)
{
    return name;
}
void player::player::set_id(int new_id)
{
	player_id = new_id;
}
int player::player::get_id(void)
{
	return player_id;
}
void player::player::add_score(int newScore)
{
	score += newScore;
}

player::player::~player(void)
{
}
