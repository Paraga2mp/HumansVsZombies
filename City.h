#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <Windows.h>
#include "GameSpecs.h"

using namespace std;

class Organism;

const int GRID_WIDTH = 20;
const int GRID_HEIGHT = 20;

class City
{
protected:
	Organism *grid[GRID_HEIGHT][GRID_WIDTH];

public:

	//Constructor & Destructor
	City();
	virtual ~City();

	//Getters and Setters
	Organism *getOrganism(int x, int y);
	void setOrganism(Organism *organism, int x, int y);

	//Methods
	void move();
	int numberOfHumans();
	int numberOfZombies();

	//friend functions & overrides output operator
	friend ostream& operator<<(ostream &output, City &city);

};//end class City

#endif