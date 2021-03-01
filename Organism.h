#ifndef ORGANISM_H
#define ORGANISM_H

#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

class City;

class Organism
{
protected:
    int x;
    int y;
    int width;
    int height;
    int recruitCount;
    bool moved, recruited;
    City *city;

	enum { WEST, NORTH, EAST, SOUTH, NORTH_EAST, NORTH_WEST, SOUTH_EAST, SOUTH_WEST};

public:
	//Default Constructors
	Organism();
	//Constructors with parameters
	Organism(City *city, int width, int height);
	//Destructor
	virtual ~Organism();

	//Virtual methods, need to be overridden.
	virtual void move() = 0;	
	virtual void recruit() = 0;

	//Getters and Setters
	void setPosition(int x, int y);

	bool getMoved();
	void setMoved(bool moved);

	bool getRecruit();
	void setRecruit(bool recruit);

	int getRecruitCount();
	void setRecruitCount(int recruitCount);

	//friend output functions which overrides output operator
	friend ostream& operator<<(ostream &output, Organism *organism);
};

#endif