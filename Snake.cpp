#include "Snake.h"
const int WIDTH = 50;
const int HEIGHT = 25;

Snake::Snake(COORD pos, int vel) 
{
	// position velocity lenght and direction of the snake all important stuff thats in the constructor 
	//because it needs to be initialized at the start of the program
	this->pos = pos;
	this->vel = vel;
	len = 1;
	direction = 'n';
	body.push_back(pos);
}

void Snake::change_dir(char dir) 
{
	direction = dir;

}
void Snake::move_snake() 
{
	switch (direction)
	{
	case 'u': pos.Y -= vel;

		break;
	case 'd': pos.Y += vel;

		break;
	case 'l': pos.X -= vel;

		break;
	case 'r': pos.X += vel;

		break;
	}
	body.push_back(pos);
	if (body.size() > len)
	{
		body.erase(body.begin());
	}
}

COORD Snake::get_pos()
{
	return pos; 
}

bool Snake::eaten(COORD food_pos)
{

	if (food_pos.X == pos.X && food_pos.Y == pos.Y)
	{
		return true; 
	}
	else 
	{
		return false;
	}

	
}

void Snake::grow()
{
	len++;
}
vector <COORD> Snake::get_body()
{
	return body;
}
bool Snake::collided()
{
	if (pos.X < 1 || pos.X > WIDTH-2 || pos.Y < 1 || pos.Y > HEIGHT-2)
	{
		return true;
	}
	for (int i = 0; i < body.size()-1; i++)
	{
		if (pos.X == body[i].X && pos.Y == body[i].Y)
		{
			return true;
		}
	}
		return false;
}