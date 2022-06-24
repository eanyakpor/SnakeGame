#ifndef FOOD_H
#define FOOD_H

#include <windows.h>
#include <cstdlib>

class Food
{

public:

	void gen_food();
	COORD get_pos();

private:
	COORD pos;


};

#endif FOOD_H

