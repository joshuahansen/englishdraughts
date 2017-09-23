/***********************************************************************
*	COSC1254 - PROGRAMMING USING C++
*	SEMESTER 2 2017
*	ASSIGNMENT 2 - ENGLISH DRAUGHTS
*	NAME:		JOSHUA HANSEN
*	STUDENT NUMBER: S3589185
************************************************************************/
#include "menu.h"

#pragma once

namespace draughts
{
    namespace ncview
    {
        class main_menu : public menu
        {
            static const std::vector<std::string> strings;
            public:
                main_menu(void);
                virtual ~main_menu(void);
        };
    }
}
