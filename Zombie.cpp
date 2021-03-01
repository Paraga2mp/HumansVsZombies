#include <algorithm>
#include <random>
#include <chrono>
#include "Zombie.h"
#include "Human.h"
using namespace std;

//Default Constructor
Zombie::Zombie(){}

//Constructor
Zombie::Zombie(City *city, int width, int height)
{
	this->city = city;
	this->width = width;
	this->height = height;
	this->starve = 0;
}

//Destructor
Zombie::~Zombie(){}

//Methods overridden from super class , for Zombie move method also implements move and eat
void Zombie::move(){

	vector<int> moveDirections;
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();//create random seed using system clock

	//Checks all adjacent and diagonal cells to see if there is a human in it to eat.
	if (y - 1 >= 0 && dynamic_cast<Human*>(city->getOrganism(x, y - 1)) != NULL){
	    moveDirections.push_back(NORTH);
	}
	if (y + 1 < height && dynamic_cast<Human*>(city->getOrganism(x, y + 1)) != NULL){
	    moveDirections.push_back(SOUTH);
	}
	if (x + 1 < width && dynamic_cast<Human*>(city->getOrganism(x + 1, y)) != NULL){
	    moveDirections.push_back(EAST);
	}
	if (x - 1 >= 0 && dynamic_cast<Human*>(city->getOrganism(x - 1, y)) != NULL){
	    moveDirections.push_back(WEST);
	}
	if (y - 1 >= 0 && x + 1 < width && dynamic_cast<Human*>(city->getOrganism(x + 1, y - 1)) != NULL){
	    moveDirections.push_back(NORTH_EAST);
	}
	if (y + 1 < height && x + 1 < width && dynamic_cast<Human*>(city->getOrganism(x + 1, y + 1)) != NULL){
	    moveDirections.push_back(SOUTH_EAST);
	}
	if (y - 1 >= 0 && x - 1 >= 0 && dynamic_cast<Human*>(city->getOrganism(x - 1, y - 1)) != NULL){
	    moveDirections.push_back(NORTH_WEST);
	}
	if (y + 1 < height && x - 1 >= 0 && dynamic_cast<Human*>(city->getOrganism(x - 1, y + 1)) != NULL){
	    moveDirections.push_back(SOUTH_WEST);
	}

	//No human to eat, so Zombie movies
	if (!moveDirections.empty())
		this->setStarve(0);
	else
	{
		this->setStarve(this->getStarve() + 1); //increments starveCount

		//Checking if there are valid move directions and adds to moveDirection vector
		if (y - 1 >= 0 && city->getOrganism(x, y - 1) == NULL){
		    moveDirections.push_back(NORTH);
		}
		if (y + 1 < height && city->getOrganism(x, y + 1) == NULL){
		    moveDirections.push_back(SOUTH);
		}
		if (x + 1 < width && city->getOrganism(x + 1, y) == NULL){
		    moveDirections.push_back(EAST);
		}
		if (x - 1 >= 0 && city->getOrganism(x - 1, y) == NULL){
		    moveDirections.push_back(WEST);
		}
	}

	if (!moveDirections.empty()){

	    //Shuffle the vector to get a random direction
        shuffle(moveDirections.begin(),moveDirections.end(),default_random_engine(seed));
        int move = moveDirections.at(0);
		
		//Sets previous cell to null
		city->setOrganism(NULL, x, y);

		//Sets the new position
		switch(move){
		    case NORTH:
                this->setPosition(x, y - 1);
		        break;
		    case SOUTH:
                this->setPosition(x, y + 1);
		        break;
		    case EAST:
                this->setPosition(x + 1, y);
		        break;
		    case WEST:
                this->setPosition(x - 1, y);
		        break;
		    case NORTH_EAST:
                this->setPosition(x + 1, y - 1);
		        break;
		    case SOUTH_EAST:
                this->setPosition(x + 1, y + 1);
		        break;
		    case NORTH_WEST:
                this->setPosition(x - 1, y - 1);
		        break;
		    case SOUTH_WEST:
                this->setPosition(x - 1, y + 1);
		        break;
		}

		//adds the zombie to the city
		city->setOrganism(this, x, y);

	}//end if

	this->setMoved(true);
	this->starveZombie(); //calls method to check if zombie has starved.

}//end move


//Implements recruit method of Organism
void Zombie::recruit(){

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();//create random seed using system clock

	//check if the zombie recruitCount limit is met
	if (this->getRecruitCount() >= ZOMBIE_BREED){
		vector<int> moveDirections;

		//Check if human in adjacent cell or diagonal
		if (y - 1 >= 0 && dynamic_cast<Human*>(city->getOrganism(x, y - 1)) != NULL){
		    moveDirections.push_back(NORTH);
		}
		if (y + 1 < height && dynamic_cast<Human*>(city->getOrganism(x, y + 1)) != NULL){
		    moveDirections.push_back(SOUTH);
		}
		if (x + 1 < width && dynamic_cast<Human*>(city->getOrganism(x + 1, y)) != NULL){
		    moveDirections.push_back(EAST);
		}
		if (x - 1 >= 0 && dynamic_cast<Human*>(city->getOrganism(x - 1, y)) != NULL){
		    moveDirections.push_back(WEST);
		}
		if (y - 1 >= 0 && x + 1 < width && dynamic_cast<Human*>(city->getOrganism(x + 1, y - 1)) != NULL){
		    moveDirections.push_back(NORTH_EAST);
		}
		if (y + 1 < height && x + 1 < width && dynamic_cast<Human*>(city->getOrganism(x + 1, y + 1)) != NULL){
		    moveDirections.push_back(SOUTH_EAST);
		}
		if (y - 1 >= 0 && x - 1 >= 0 && dynamic_cast<Human*>(city->getOrganism(x - 1, y - 1)) != NULL){
		    moveDirections.push_back(NORTH_WEST);
		}
		if (y + 1 < height && x - 1 >= 0 && dynamic_cast<Human*>(city->getOrganism(x - 1, y + 1)) != NULL){
		    moveDirections.push_back(SOUTH_WEST);
		}

		//Check if there are values in the vector
		if (!moveDirections.empty())
		{
		    //Shuffle the vector to get random move location
            shuffle(moveDirections.begin(),moveDirections.end(),default_random_engine(seed));
            int newPosition = moveDirections.at(0);//get random move from vector

			//create new zombie
			Zombie *myZombie = new Zombie(city, GRID_WIDTH, GRID_HEIGHT);

			//Get zombie's new position
			switch(newPosition){
			    case NORTH:
                    myZombie->setPosition(x, y - 1);
			        break;
			    case SOUTH:
                    myZombie->setPosition(x, y + 1);
			        break;
			    case EAST:
                    myZombie->setPosition(x + 1, y);
			        break;
			    case WEST:
                    myZombie->setPosition(x - 1, y);
			        break;
			    case NORTH_EAST:
                    myZombie->setPosition(x + 1, y - 1);
			        break;
			    case SOUTH_EAST:
                    myZombie->setPosition(x + 1, y + 1);
			        break;
			    case NORTH_WEST:
                    myZombie->setPosition(x - 1, y - 1);
			        break;
			    case SOUTH_WEST:
                    myZombie->setPosition(x - 1, y + 1);
			        break;
			}

			//Set the Zombie to the city
			city->setOrganism(myZombie, myZombie->x, myZombie->y);

			//set new zombie moved, recruited to true,
			myZombie->setMoved(true);
			myZombie->setRecruitCount(0);
			myZombie->setRecruit(true);

		}//end if

	}//end if

	else
		this->setRecruitCount(this->getRecruitCount() + 1); //increase the recruitCount

}//end recruit

//Getters and Setters
void Zombie::setStarve(int eat){
    this->starve = eat;
}
int Zombie::getStarve(){
    return this->starve;
}

//Implements starveZombie method of Organism
void Zombie::starveZombie()
{
	//if zombie has not eaten by human in 3 turns, it converts into a human
	if (this->getStarve() >= ZOMBIE_STARVE)
	{
		Human *myHuman = new Human(city, GRID_WIDTH, GRID_HEIGHT);
		myHuman->setPosition(x, y);
		city->setOrganism(myHuman, x, y);

	}//end if

}//end starveZombie
