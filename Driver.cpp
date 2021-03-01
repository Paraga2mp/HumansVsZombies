#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <Windows.h>
#include "City.h"
#include "Human.h"
#include "Zombie.h"
using namespace std;


int numberOfHumans = 0;
int numberOfZombies = 0;
int numberOfIterations = 0;
City *city = new City();
HANDLE  hColor = GetStdHandle(STD_OUTPUT_HANDLE);


//Prototype
void getStep();



int main() {

    double counter = 0;
    int count = 0;
    clock_t startTime = clock();
    clock_t previousTime = startTime;

    cout << "     Welcome to the Humans Vs Zombies Game!" <<endl<<endl;

    //Creat the City with Humans
    do {
        int ranX = rand() % GRID_WIDTH;
        int ranY = rand() % GRID_HEIGHT;
        int randomRecruit = rand() % 4;

        //Create and put human in random empty location
        if (city->getOrganism(ranX, ranY) == NULL) {
            Human *myHuman = new Human(city, GRID_WIDTH, GRID_HEIGHT);
            myHuman->setPosition(ranX, ranY);
            myHuman->setRecruitCount(randomRecruit);
            city->setOrganism(myHuman, ranX, ranY);
            numberOfHumans++;
            PAUSE_SECONDS;
        }

    } while (numberOfHumans < HUMAN_STARTCOUNT);

    //Create the city with Zombies
    do {
        int ranX = rand() % GRID_WIDTH;
        int ranY = rand() % GRID_HEIGHT;
        int randomRecruit = rand() % 9;

        ////Create and put zombie in random empty location
        if (city->getOrganism(ranX, ranY) == NULL) {
            Zombie *myZombie = new Zombie(city, GRID_WIDTH, GRID_HEIGHT);
            myZombie->setPosition(ranX, ranY);
            myZombie->setRecruitCount(randomRecruit);
            city->setOrganism(myZombie, ranX, ranY);
            numberOfZombies++;
        }

    } while (numberOfZombies < ZOMBIE_STARTCOUNT);

    //Iterate the getStep using the timer
    while (numberOfHumans > 0 && numberOfZombies > 0 && count < ITERATIONS) {
            startTime = clock();
            counter += startTime - previousTime;
            previousTime = startTime;
            if (counter > PAUSE_SECONDS * CLOCKS_PER_SEC) {
                counter -= PAUSE_SECONDS * CLOCKS_PER_SEC;
                getStep();
                count++;
            }
    }

        //Output the Winner to the console
        if(numberOfHumans == 0 || numberOfZombies == 0) {
            if (numberOfHumans > 0 && numberOfHumans >= numberOfZombies){
                cout << "     Humans Won!";
            }
            else {
                cout << "     Zombies Won!";
            }

        } else{
            cout << " Neither Human nor Zombie won the Game in " << count << " Iterations!!!" <<endl;
        }

        return 0;

} //end Main


//Declare the method that moves and print the city to the console
void getStep()
{
    city->move();
    numberOfHumans = city->numberOfHumans();
    numberOfZombies = city->numberOfZombies();
    numberOfIterations++;

    //Draw The city
    cout << *city;
    cout << "     Iterations: " << numberOfIterations;
    SetConsoleTextAttribute(hColor, HUMAN_COLOR);//bright blue
    cout << "  Humans: " << numberOfHumans;
    SetConsoleTextAttribute(hColor, ZOMBIE_COLOR);//bright red
    cout << "  Zombies: " << numberOfZombies << "       " << endl << endl;

}//end getStep


