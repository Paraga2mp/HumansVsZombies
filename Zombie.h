#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <vector>
#include "Organism.h"
#include "City.h"
using namespace std;

//Zombie inherits from Organism Class
class Zombie : public Organism
{
protected:
	int starve;

public:
	//Constructors & Destructor
	Zombie();
	Zombie(City *city, int width, int height);
	virtual ~Zombie();

	//Methods inherited from super class
	void move();
	void recruit();

	//Getters and Setters
	int getStarve();
	void setStarve(int eat);

	//Methods
	void starveZombie();
};

#endif