#ifndef HUMAN_H
#define HUMAN_H

#include <vector>
#include "Organism.h"
#include "City.h"
using namespace std;

class Human : public Organism //inherits from Organism Class
{
public:
	//Constructor & Destructors
	Human();
	Human(City *city, int width, int height);
	virtual ~Human();

	//Methods signature, need to be implemented
	void move();
	void recruit();

};//end class Human

#endif