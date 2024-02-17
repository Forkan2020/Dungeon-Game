// 5G00DL97 - 3004 Programming Languages 2
// Project work, Phase 3: Ready Game!!! 
// Developed by: Md Forkan Hossain.

#include<iostream>
#include<string>
#include<ctime>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
#include <vector>
#include<fstream>
#include<sstream>

#include"Game_class.h"

using namespace std;


//Class Game

Game::Game(int m, int n, char sign) {
	this->p.value2 = m;
	this->p.value1 = n;
	this->sign = sign;
}
Game::Game() {
	this->p.value2 = 0;
	this->p.value1 = 0;
	this->sign = ' ';
}
void Game::setPosition(int aaa, int bbb) {
	position(aaa, bbb);
}
char Game::getSympol() const {
	return sign;
}
position Game::getPosition() {
	return this->p;
}


//Class Gem

Gem::Gem(int aaa, int bbb, char sign, int point) :Game(aaa, bbb, sign) {
	// just to set Gem positions and symbol
	this->point = point;
}
Gem::Gem() {
	point = 0;
}
int Gem::getPoint() const {
	return point;
}


// Class position

position::position(int m, int n)
{
	this->value1 = n;
	this->value2 = m;
}
position::position()
{
	this->value1 = 0;
	this->value2 = 0;
}
int position::getPositionX() const {
	return value2;
}
int position::getPositionY() const {
	return value1;
}

// class player     // set player's symbol P          
Player::Player() {
	this->point = 0;
}
Player::Player(int aaa, int bbb, char sign, int point, int energy) :Game(aaa, bbb, sign) {
	// just to set player positions and symbol
	this->point = point;
	this->energy = energy;  // get the energy 
}
int Player::getEnergy() const {
	return energy;   // get the energy 
}
int Player::getPoints() const {
	return point;   // get the points
}

//Class MagicApple

MagicApple::MagicApple(int aaa, int bbb, char sign, int energy) :Game(aaa, bbb, sign) {
	// just to set MagicApple positions and symbol
	this->energy = energy;
}
MagicApple::MagicApple() {
	this->energy = 0;
}
int MagicApple::getEnergy() const {
	return energy;
}


//Class Monster

Monster::Monster(int aaa, int bbb, char sign, int strength) :Game(aaa, bbb, sign) {    // just to set monster positions and symbol
	this->strength = strength;
}
Monster::Monster() {
	this->strength = 0;
}
int Monster::getStrength() const {
	return strength;
}



//Class map    

int map::level = 0;

map::map(int w, int h) {  // width and height for the map
	this->w = w;
	this->h = h; //this->level = level;
}
map::map() {  // just to set map positions and symbol
	this->w = 0;
	this->h = 0;
	this->level = 0;
}
int map::getHeight() const {
	return h;
}
int map::getWidth() const {
	return w;
}
void map::mapSet(/*Monster& m, Player& p*/) {
	level++;
	int h = getHeight();
	int w = getWidth();
	int nothing;

	if (w < h) {
		nothing = w;
		w = h;
		h = nothing;
	}

	int different = w - h;
	letter = new char* [w];
	for (int a = 0; a < w; a++) {
		letter[a] = new char[h];
	}

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			if (i == 0 || i == (h + different - 1)) {
				letter[i][j] = 'X';
			}
			else if (j == 0 || j == (w - different - 1)) {
				letter[i][j] = 'X';
			}
			else {
				int random = rand() % 8;
				if (random == 0) {
					letter[i][j] = 'X';
				}
				else {
					letter[i][j] = '.';
				}
			}
		}
	}
}

int map::getLevel() const {
	return level;
}
void map::step_player(Monster* m, int shape1, Player& p, MagicApple* a, int shape2, Gem* g, int shape3)
{

	position* m_position = new position[shape1];
	position* a_position = new position[shape2];
	position* g_position = new position[shape3];
	for (int i = 0; i < shape2; i++)
	{
		m_position[i] = m[i].getPosition();
		a_position[i] = a[i].getPosition();
		g_position[i] = g[i].getPosition();
	}
	
	position location_p = p.getPosition();

	for (int i = 0; i < shape2; i++) {
		letter[m_position[i].value2 - 1][m_position[i].value1 - 1] = m[i].getSympol();
		letter[a_position[i].value2 - 1][a_position[i].value1 - 1] = a[i].getSympol();
		letter[g_position[i].value2 - 1][g_position[i].value1 - 1] = g[i].getSympol();
	}
	letter[location_p.value2 - 1][location_p.value1 - 1] = p.getSympol();
	
	delete[] m_position;
	delete[] a_position;
	delete[] g_position;
}


//player p for print enery and point
void map::print(Player& p)
{
	if (p.getEnergy() > 0) {
		cout << "Level: " << level << "; player energy: " << p.getEnergy() << "%; points: " << p.getPoints();
		cout << endl;
		int nothing;
		if (w < h) {
			nothing = w;
			w = h;
			h = nothing;
		}
		//cout << "map " << to_string(w) << "*" << to_string(h) 
		cout << endl << endl;
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < h; j++)
			{
				cout << letter[i][j];
			}
			cout << endl;
		}
	}
	else if (p.getEnergy() == 0)
	{
		system("CLS");
		cout << endl;
		//cout << endl << endl;
		// Ending message

		cout << " Game Over!!!      " << endl  << endl;
		cout << " Thank you for playing my game... " << endl << endl;;  // if player wants to play again or not
		cout << " GOOD BYE!\n";
	}
}

map::~map() {
	cout << " Please Close The screen." << endl << endl ;
	for (int i = 0; i < w; i++)
		delete[] letter[i];   // Ending process

	delete[] letter;
}
