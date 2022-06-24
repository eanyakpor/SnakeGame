#ifndef SNAKE_H
#define SNAKE_H

#include <windows.h>
#include <vector>
using namespace std; // should never so but following the guide. This is because of namespace pollution
class Snake
{



public:
	Snake(COORD pos, int vel);

	void change_dir(char dir); // change direction 

	void move_snake();  // move snake

	COORD get_pos(); // get current position of snake 

	bool eaten(COORD pos); // states whether the snake ate the food or not 

	void grow(); // function to grow the snake 

	bool collided(); // returns true if position of x is less than 1, means youve crossed the wall

	vector<COORD> get_body();
private:
	COORD pos;
	int len;
	int vel;
	char direction;
	vector<COORD> body;
	
	
};

#endif