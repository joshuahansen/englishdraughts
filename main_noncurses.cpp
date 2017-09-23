/***********************************************************************
*	COSC1254 - PROGRAMMING USING C++
*	SEMESTER 2 2017
*	ASSIGNMENT 2 - ENGLISH DRAUGHTS
*	NAME:		JOSHUA HANSEN
*	STUDENT NUMBER: S3589185
************************************************************************/
#include "ncview/ui.h"
#include "nc_controller/controller.h"
#include "model/model.h"

int main(void)
{
    draughts::ncview::ui * view = draughts::ncview::ui::get_instance();
    atexit(draughts::ncview::ui::delete_instance);
    atexit(draughts::nc_controller::controller::delete_instance);
    atexit(draughts::model::model::delete_instance);
    view->main_menu();
}
