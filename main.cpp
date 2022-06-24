#include <iostream>
#include <ctime>
#include "Snake.h"
#include <conio.h>
#include "Food.h"
using namespace std;
#define KEY_UP 72

#define KEY_DOWN 80

#define KEY_LEFT 75

#define KEY_RIGHT 77

#define WIDTH  50
#define HEIGHT  25

int x = 10;
int y = 10;
int score = 0;
Snake snake({WIDTH / 2, HEIGHT / 2}, 1); // makes snake go in the middle 
Food food; 



void board() {

	COORD snake_pos = snake.get_pos();
	COORD food_pos = food.get_pos();

	

	vector<COORD> snake_body = snake.get_body();
	cout << "SCORE : " << score << "\n\n";

	for (int i = 0; i < HEIGHT; i++) 
	{
		cout << "\t\t\t#";
		for (int j = 0; j < WIDTH-2; j++) 
		{
			if (i == 0 || i == HEIGHT - 1)
			{
				cout << "#";

			
				
			}
			else if (i == snake_pos.Y && j+1 == snake_pos.X) 
			{
			cout << "0"; 
			}
			else if (i == food_pos.Y && j+1 == food_pos.X)
			{
				cout << "@";
			}
			else 
			{
				bool isBodyPart = false;
				for (int k = 0; k < snake_body.size()-1; k++)
				{
					if (i == snake_body[k].Y && j + 1 == snake_body[k].X)
					{
						cout << "o";
						isBodyPart = true;
						break;
					}
				}
				if (!isBodyPart)
				{
					cout << " ";
				}
			}
			
		}
		cout << "#" << endl; // this should be a new line. 
	}
	}

/*
coordinate system on a computer starts at top left. so 0,0 is the top left of the computer screen.
so y increases down and decreases up. x stays the same. so x to the right increases and x to the left decreses.

*/

/*
try to implement growing the snake with a linked list. A vector doesn't need a fixed size but it wastes space
*/


int main() 
{
	score = 0;
	srand(time(NULL));
	food.gen_food();


	bool game_over = false;
	
	while (!game_over) 
	{
		board();
		if (_kbhit())
		{
			switch (_getch())
			{
			// asci values of the arrow keys if wrong subsitute for w, s, d, a 
			// vertical its goes super fast but thats because of the console nothing you can do about that
			// i defined the arrow keys but ill use w s d a for now because its easier 
			// maybe at a certain level i can switch to arrow keys?
			//nvm its always going to be like that

			case 72: snake.change_dir('u'); 
				break;
			
			case 75: snake.change_dir('l');
				break;
			
			case 80: snake.change_dir('d');
				break;
			
			case 77: snake.change_dir('r');
				break;
			}
		}
		snake.move_snake();
		// check whether the food was eaten or not
		if (snake.eaten(food.get_pos()))
		{
			food.gen_food();
			snake.grow();
			score = score + 10;
		}
		if (snake.collided())
		{
			game_over = true;
		}
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
	}
	
	
	
	
	/*
	learned a lot figured the origin point of a  console is on the top right 
	y down increases and y top decreases x axis stays the same. Game is to damn fast lol. 
	fun experinece definelty going to be implementing some more. 
	*/
	return 0;
} 