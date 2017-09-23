/***********************************************************************
*	COSC1254 - PROGRAMMING USING C++
*	SEMESTER 2 2017
*	ASSIGNMENT 2 - ENGLISH DRAUGHTS
*	NAME:		JOSHUA HANSEN
*	STUDENT NUMBER: S3589185
************************************************************************/
#include "window.h"
#pragma once
namespace draughts
{
    namespace ncview
    {
        class add_player_window : public window
        {
            public:
            virtual void activate(void) override;
            virtual ~add_player_window(void){}
        };
    }
}
