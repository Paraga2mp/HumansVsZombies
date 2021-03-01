#include "Organism.h"
#include "Human.h"
#include "Zombie.h"
using namespace std;

//Default Constructor
Organism::Organism(){}

//Constructor with parameters
Organism::Organism(City *city, int width, int height)
{
	this->city = city;
	this->width = width;
	this->height = height;
}

//Destructor
Organism::~Organism(){}

//Getters and Setters Methods
void Organism::setPosition(int x, int y){
    this->x = x;this->y = y;
}
void Organism::setMoved(bool moved){
    this->moved = moved;
}
bool Organism::getMoved(){
    return this->moved;
}
void Organism::setRecruit(bool recruited){
    this->recruited = recruited;
}
bool Organism::getRecruit(){
    return this->recruited;
}
void Organism::setRecruitCount(int recruitCount){
    this->recruitCount = recruitCount;
}
int Organism::getRecruitCount(){
    return this->recruitCount;
}

//friend function which overrides output operation
ostream& operator<<(ostream &output, Organism *organism)
{
	HANDLE  hColor = GetStdHandle(STD_OUTPUT_HANDLE); //Changes the output color

	//Depending on Human or Zombie, will output 'H' or 'Z', respectfully
	if (dynamic_cast<Human*>(organism) != NULL) //Human
	{
		SetConsoleTextAttribute(hColor, HUMAN_COLOR);
		output << HUMAN_CH;
	}
	else if (dynamic_cast<Zombie*>(organism) != NULL) //Zombie
	{
		SetConsoleTextAttribute(hColor, ZOMBIE_COLOR);
		output << ZOMBIE_CH;
	}
	else //Empty space
		output << SPACE_CH;

	return output;

}//end friend function








