// 5G00DL97 - 3004 Programming Languages 2
// Project work, Phase 3: Ready Game !!! 
// Developed by: Md Forkan Hossain.


#include<iostream>
#include<string>
#include<ctime>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
#include <iostream>
#include<fstream>
#include<sstream>

#include"Game_class.h"

using namespace std;  //void draw(map& level, Player& p, Monster* m_group, MagicApple* a_group, Gem* g_group);

void object(map& level, Monster* m, int shape1, Player& p, MagicApple* a, int shape2, Gem* g, int shape3)
{
	level.mapSet();
	level.step_player(m, shape1, p, a, shape2, g, shape3);
	level.print(p);
}

void display() //clear screen
{
	COORD Position;
	HANDLE out;

	out = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(out, Position);
}

void area() //clear box without blinking
{
	DWORD Write;
	HANDLE exit;
	COORD Position;

	exit = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 20;
	FillConsoleOutputCharacter(exit, ' ', 1000000, Position, &Write);

	SetConsoleCursorPosition(exit, Position);
}

void step(map& level, Player& p, MagicApple* a, Monster* m, Gem* g)
{
	position location_p = p.getPosition();

	//player
	int orginal_x_p = location_p.value2 - 1;
	int orginal_y_p = location_p.value1 - 1;
	char steps;
	cout << endl;
	cout << "press: a for left; d for right; w for up; s for down" << endl;
	cout << "Please select action (move with wasd or Q to escape)" << endl;
	
	//cin.get(step);
	cin >> steps;

	while (steps != 'Q' && steps != 'q') {
		if (p.energy == 0) {
			steps = 'Q';
		}
		switch (steps) {
		case 'a':
			display();

			if (steps != 'Q') {
				//p.energy = p.energy - 5;
				if (level.letter[orginal_x_p][orginal_y_p - 1] != 'X') {
					if (level.letter[orginal_x_p][orginal_y_p - 1] == 'A') {
						//int random = rand() % 10;
						p.energy = p.energy - 5;
						p.energy = p.energy + a[0].getEnergy();
					}
					else if (level.letter[orginal_x_p][orginal_y_p - 1] == 'M') {
						p.energy = p.energy - 5;
						p.energy = p.energy - m[0].getStrength();
					}
					else if (level.letter[orginal_x_p][orginal_y_p - 1] == 'G') {
						p.energy = p.energy - 5;
						p.point = p.point + g[0].getPoint();
					}
					else if (level.letter[orginal_x_p][orginal_y_p - 1] == '.') {
						p.energy = p.energy - 5;
					}

					level.letter[orginal_x_p][orginal_y_p] = '.';
					level.letter[orginal_x_p][orginal_y_p - 1] = p.getSympol();
					orginal_y_p = orginal_y_p - 1;
				}
				//system("CLS");
				//clearScreen();
				level.print(p);
				if (p.energy != 0) {
					cout << endl;
					cout << "press: a for left; d for right; w for up; s for down" << endl;
					cout << "Please select action (move with wasd or Q to escape)" << endl;
				
					cin >> steps;
				}
				area(); //cleararea();
			}
			break;
		case 's':
			display();
			//minus energy everytiem move
			//p.energy=p.energy - 5;
			if (steps != 'Q') {
				if (level.letter[orginal_x_p + 1][orginal_y_p] != 'X') {
					if (level.letter[orginal_x_p + 1][orginal_y_p] == 'A') {
						p.energy = p.energy - 5;
						p.energy = p.energy + a[0].getEnergy();
					}
					else if (level.letter[orginal_x_p + 1][orginal_y_p] == 'M') {
						p.energy = p.energy - 5;
						p.energy = p.energy - m[0].getStrength();
					}
					else if (level.letter[orginal_x_p + 1][orginal_y_p] == 'G') {
						p.energy = p.energy - 5;
						p.point = p.point + g[0].getPoint();
					}
					else if (level.letter[orginal_x_p + 1][orginal_y_p] == '.') {
						p.energy = p.energy - 5;
					}
					level.letter[orginal_x_p][orginal_y_p] = '.';
					level.letter[orginal_x_p + 1][orginal_y_p] = p.getSympol();
					orginal_x_p = orginal_x_p + 1;
				}
				//system("CLS");
				//display();
				level.print(p);
				
				if (p.energy != 0) {
					cout << endl;
					cout << "press: a for left; d for right; w for up; s for down" << endl;
					cout << "Please select action (move with wasd or Q to escape)" << endl;
				
					cin >> steps;
				}
				
				area(); //cleararea();
			}

			break;
		case 'w':
			display();
			//p.energy=p.energy - 5;
			if (steps != 'Q') {
				if (level.letter[orginal_x_p - 1][orginal_y_p] != 'X') {
					if (level.letter[orginal_x_p - 1][orginal_y_p] == 'A') {
						p.energy = p.energy - 5;
						p.energy = p.energy + a[0].getEnergy();
					}
					else if (level.letter[orginal_x_p - 1][orginal_y_p] == 'M') {
						p.energy = p.energy - 5;
						p.energy = p.energy - m[0].getStrength();
					}
					else if (level.letter[orginal_x_p - 1][orginal_y_p] == 'G') {
						p.energy = p.energy - 5;
						p.point = p.point + g[0].getPoint();
					}
					else if (level.letter[orginal_x_p - 1][orginal_y_p] == '.') {
						p.energy = p.energy - 5;
					}
					level.letter[orginal_x_p][orginal_y_p] = '.';
					level.letter[orginal_x_p - 1][orginal_y_p] = p.getSympol();
					orginal_x_p = orginal_x_p - 1;
				}
				//system("CLS");
				//display();
				level.print(p);

				if (p.energy != 0)
	{ 
					cout << endl;
					cout << "press: a for left; d for right; w for up; s for down" << endl;
					cout << "Please select action (move with wasd or Q to escape)" << endl;
					
					cin >> steps;
				}
				area();
			}

			break;
		case 'd':
			display();
			//move = _getch();
			if (steps != 'Q')
			{
				if (level.letter[orginal_x_p][orginal_y_p + 1] != 'X') {
					if (level.letter[orginal_x_p][orginal_y_p + 1] == 'A') {
						p.energy = p.energy - 5;
						p.energy = p.energy + a[0].getEnergy();
					}
					else if (level.letter[orginal_x_p][orginal_y_p + 1] == 'M') {
						p.energy = p.energy - 5;
						p.energy = p.energy - m[0].getStrength();
					}
					else if (level.letter[orginal_x_p][orginal_y_p + 1] == 'G') {
						p.energy = p.energy - 5;
						p.point = p.point + g[0].getPoint();
					}
					else if (level.letter[orginal_x_p][orginal_y_p + 1] == '.') {
						p.energy = p.energy - 5;
					}
					level.letter[orginal_x_p][orginal_y_p] = '.';
					level.letter[orginal_x_p][orginal_y_p + 1] = p.getSympol();
					orginal_y_p = orginal_y_p + 1;
				}
				//system("CLS");
				//display();
				level.print(p);
				if (p.energy != 0) {
					cout << endl;
					cout << "press: a for left; d for right; w for up; s for down" << endl;
					cout << "Please select action (move with wasd or Q to escape)" << endl;
					
					cin >> steps;
				}
				area(); //cleararea();
			}
			break;
		default:
			if (steps != 'Q') {
				display();
				level.print(p);
				cout << endl;
				cout << "press: a for left; d for right; w for up; s for down" << endl;
				cout << "Please select action (move with wasd or Q to escape)" << endl;
				
				//cin.get(move);
				cin >> steps;
				system("CLS");
				break;
			}
		}

	}
}


void start(map& level, int shape1, int shape2, int shape3)
{

	Player p(6, 6, 'P', 0, 100);

	Monster* m_group = new Monster[shape1];
	MagicApple* a_group = new MagicApple[shape2];
	Gem* g_group = new Gem[shape3];

	m_group[0] = Monster(5, 6, 'M', 5);
	m_group[1] = Monster(6, 7, 'M', 5);

	a_group[0] = MagicApple(8, 8, 'A', 10);
	a_group[1] = MagicApple(7, 7, 'A', 10);

	g_group[0] = Gem(11, 11, 'G', 5);
	g_group[1] = Gem(2, 2, 'G', 5);
	//g_group[2] = Gem(3, 3, 'G', 5);
	object(level, m_group, shape1, p, a_group, shape2, g_group, shape3);
	//object(level, m, p, a,g);
	step(level, p, a_group, m_group, g_group);

	delete[] m_group;
	delete[] a_group;
	delete[] g_group;
}


/*
A is Magic Apple, it will help you increase your energy.
M is Monster, it will decrease your energy
G is Gem, the more gem you have the more point for you
P is player, it is you on the map

a move left
s move down 
d move right 
w move up
q for quit game 
Game Over when your energy = 0 
there will be more gem, magic apple, monter and bigger map when you go to higher level 

*/


int main()
{
	// welcome message 
//cout << "\t\t\t-=-=-=-=-=-=-=-=-=-=-WELCOME TO-=-=-=-=-=-=-=-=-=-" << endl;
//cout << "\t\t\t-=-=-=-=-=-=-=-=- TREASURE HUNTING -=-=-=-=-=-=-=-" << endl;
//cout << "\t\t\t-=-=-=-=-=-=-=-=-=-=-=- GAME -=-=-=-=-=-=-=-=-=-=-" << endl << endl << endl;
//cout << endl;
	cout << "Welcome to the treasure Hunt! " << endl;
	cout << "Entered into the magical dungeon, Good luck ! " << endl;
	

	srand(static_cast<unsigned int>(time(NULL)));
	map m(20, 20); // initialize height and width for the game
/*  
To store different grids/tiles
	EMPTY = '.',
	MONSTER = 'M',
	GEM = 'G',
	EXIT = 'q',
	PLAYER = 'P' 
	Wall = 'X'
*/
	int shape1 = 2 + m.getLevel();
	int shape2 = 2 + m.getLevel();
	int shape3 = 2 + m.getLevel();
	//cout << shape1;
	start(m, shape1, shape2, shape3);
	return 0;
}