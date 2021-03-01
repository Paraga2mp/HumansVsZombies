#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "Human.h"


using namespace std;

//Default constructor
Human::Human(){}

//Constructor with parameters
Human::Human(City *city, int width, int height)
{
	this->city = city;
	this->width = width;
	this->height = height;
}

//Destructor
Human::~Human(){}

//Implements move method of Organism
void Human::move()
{
	vector<int> moveDirections; //Vector to store random values for valid moves
    unsigned seed = chrono::system_clock::now().time_since_epoch().count(); //create random seed using system clock

    //Put the valid move directions to the vector
	if (y - 1 >= 0 && city->getOrganism(x, y - 1) == NULL){
	    moveDirections.push_back(NORTH);
	}
	if (y + 1 < height && city->getOrganism(x, y + 1) == NULL){
	    moveDirections.push_back(SOUTH);
	}
	if (x - 1 >= 0 && city->getOrganism(x - 1, y) == NULL){
	    moveDirections.push_back(WEST);
	}
	if (x + 1 < width && city->getOrganism(x + 1, y) == NULL){
	    moveDirections.push_back(EAST);
	}
	
	if (!moveDirections.empty())
	{
		//Shuffle the valid move directions of the vector
        shuffle(moveDirections.begin(),moveDirections.end(),default_random_engine(seed));
        int move = moveDirections.at(0);

        //Set the Organism to the new location and put set the previous location null
		city->setOrganism(NULL, x, y);

		//Compare the move value to enum values and add the human to the new position
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
		}

		//Add human to the city
		city->setOrganism(this, x, y);
	}//end if

	//set moved value to true
	this->setMoved(true);

}//end move

//Implements recruit method of Organism
void Human::recruit(){

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();//create random seed using system clock

	//check if the human recruitCount limit is met
	if (this->getRecruitCount() >= HUMAN_BREED)
	{
		vector<int> moveDirections; //Vector to store random values for valid moves

		//stores the valid move directions into the vector
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


		if (!moveDirections.empty()){
            //Shuffle the valid move directions of the vector
            shuffle(moveDirections.begin(),moveDirections.end(),default_random_engine(seed));
            int newPosition = moveDirections.at(0);
			//creates a new human
			Human *myHuman = new Human(city, GRID_WIDTH, GRID_HEIGHT);

            //Compare the move value to enum values and add the human to the new position
            switch(newPosition){
                case NORTH:
                    myHuman->setPosition(x, y - 1);
                    break;
                case SOUTH:
                    myHuman->setPosition(x, y + 1);
                    break;
                case EAST:
                    myHuman->setPosition(x + 1, y);
                    break;
                case WEST:
                    myHuman->setPosition(x - 1, y);
                    break;
            }

			//set the human in the city
			city->setOrganism(myHuman, myHuman->x, myHuman->y);

			//Set the values for Human has moved
			myHuman->setMoved(true);
			myHuman->setRecruitCount(0); //reset recruit count
			myHuman->setRecruit(true);

		}//end if

		//set current human to 0 whether recruit or not
		this->setRecruitCount(0);
	}
	else
        //adds to recruit counter
		this->setRecruitCount(this->getRecruitCount() + 1);

}//end recruit