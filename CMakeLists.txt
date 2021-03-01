cmake_minimum_required(VERSION 3.15)
project(HumansVsZombies)

set(CMAKE_CXX_STANDARD 17)


add_executable(HumansVsZombies-Copy Driver.cpp City.cpp City.h GameSpecs.h Organism.h Organism.cpp Human.h Human.cpp Zombie.h Zombie.cpp )