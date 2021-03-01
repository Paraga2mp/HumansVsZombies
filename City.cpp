#include "City.h"
#include "Human.h"
#include "Zombie.h"
#include "Organism.h"
using namespace std;


//Constructor
City::City()
{
	//populating the city to initialize every spot on grid to null
	for (int i = 0; i < GRID_HEIGHT; i++)
	{
		for (int j = 0; j < GRID_WIDTH; j++)
			grid[j][i] = NULL;
	}
}

//Destructor
City::~City(){}


//Getters and Setters
Organism *City::getOrganism(int x, int y){
    return this->grid[x][y];
}
void City::setOrganism(Organism *organism, int x, int y){
    grid[x][y] = organism;
}


//Methods first sets all to false, then move, then recruit
void City::move()
{
	//Sets the initial bool move for all organism to false
	for (int i = 0; i < GRID_HEIGHT; i++)
	{
		for (int j = 0; j < GRID_WIDTH; j++)
		{
			if(grid[j][i] != NULL)
			{
				grid[j][i]->setMoved(false);
				grid[j][i]->setRecruit(false);
			}
		}
	}


	//Sets organisms to move
	for (int i = 0; i < GRID_HEIGHT; i++)
	{
		for (int j = 0; j < GRID_WIDTH; j++)
		{
			if (grid[j][i] != NULL)
			{
				if (grid[j][i]->getMoved() == false)
					grid[j][i]->move();
			}
		}
	}



	//Sets organisms to recruit
	for (int i = 0; i < GRID_HEIGHT; i++)
	{
		for (int j = 0; j < GRID_WIDTH; j++)
		{
			if (grid[j][i] != NULL)
			{
				if (grid[j][i]->getRecruit() == false)
					grid[j][i]->recruit();
			}
		}
	}
}//end move


//Returns the number of Humans
int City::numberOfHumans()
{
	int humans = 0;
	for (int i = 0; i<GRID_HEIGHT; i++)
	{
		for (int j = 0; j<GRID_WIDTH; j++)
		{
			if (dynamic_cast<Human*>(grid[j][i]) != NULL)
				humans++;
		}
	}
	return humans;

}//end numberOfHumans

//Returns the number of Zombies
int City::numberOfZombies()
{
	int zombies = 0;
	for (int i = 0; i<GRID_HEIGHT; i++)
	{
		for (int j = 0; j<GRID_WIDTH; j++)
		{
			if (dynamic_cast<Zombie*>(grid[j][i]) != NULL)
				zombies++;
		}
	}
	return zombies;

}//end numberOfZombies

//friend functions to override output operator
ostream& operator<<(ostream &output, City &city)
{
    //Draw the City
	for (int i = 0; i<GRID_HEIGHT; i++)
	{
		output << "     |";
		for (int j = 0; j<GRID_WIDTH; j++) {
            output << city.grid[j][i] << "|";
        }
		output << endl;
	}

	return output;

} //end friend function of output operator