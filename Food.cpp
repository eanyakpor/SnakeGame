#include "Food.h"

const int HEIGHT = 25;
const int WIDTH = 50;


void Food::gen_food()
{
	pos.X = (rand() % WIDTH-3) + 1;
	pos.Y = (rand() % HEIGHT-3) + 1; // might need to be plus one
}

COORD Food::get_pos()
{
	// returns positon of the current food 
	return pos;
}