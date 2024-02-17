// 5G00DL97 - 3004 Programming Languages 2
// Project work, Phase 3: Ready Game !!! 
// Developed by: Md Forkan Hossain.

#pragma once

void display();

class position  //class Position
{
private:

public:
	int value1, value2;
	position();
	position(int m, int n);
	int getPositionX() const;
	int getPositionY() const;
};

class Game    //class Game
{
private:
	char sign;
	position p;
	
public:
	Game();
	Game(int m, int n, char sign);
	position getPosition();
	virtual void setPosition(int m, int n);
	virtual char getSympol() const; //virtual ~Game();
};

class Gem :public Game  //class Gem
{
private:
	int point;

public:
	Gem(int bbb, int aaa, char sign, int point);
	Gem();
	int getPoint() const;  	//void setPosition(int x, int y);
	                        //position getPosition(
};

class MagicApple :public Game   //class MagicApple
{
private:
	int energy;

public:
	MagicApple(int bbb, int aaa, char sign, int energy);
	MagicApple();
	int getEnergy() const;
};


class Monster :public Game  //class Monster
{
private:
	int strength;

public:
	Monster(int bbb, int aaa, char sign, int strength);
	Monster();
	int getStrength() const;
};

class Player :public Game  // class Player
{
private:

public:
	int point, energy;
	Player(int bbb, int aaa, char sign, int point, int energy);
	Player(); 	   //void setPosition(int m, int n);
	               //int getPositionX();
	int getPoints() const;
	int getEnergy() const; //int getEnergy() const;

};

class map :public Game, position  //class Map
{
private:
	static int level;

public:
	int h, w; // height(h) , width(w)
	char** letter;
	map(int w, int h); // height(h) , width(w)
	map(); //void random();
	void step_player(Monster* m, int shape1, Player& p, MagicApple* a, int shape2, Gem* g, int shape3);
	int getHeight() const;
	int getWidth() const;
	void mapSet(/*Monster &m,Player &p*/);
	void print(Player& p);
	int getLevel() const;
	~map();
};
#pragma once
