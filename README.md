# HumansVsZombies


The goal for this programming project is to create a simple modified 2D predator-prey simulation (aka a
zombie apocalypse). In this simulation the prey are humans and the predators are zombies. These
beings live in a 20 x 20 grid of cells (a city). Only one being may occupy a cell at a time. The grid is
enclosed, so a being is not allowed to move off the edges of the city or appear on the other side. Time is
simulated in steps. Each being performs some action every time step.

Note(s):
 In this project move all the zombies first (move in the zombies case may include eating). Then
move the humans. Finally have the zombies convert then have the humans recruit (or you may
make a fully polymorphic routine that does not require down casting).

The humans behave according to the following rules (in order):
MOVE. For every time step, the humans randomly try to move (aka run screaming) up, down,
left, or right. If the neighboring cell in the selected direction is occupied or would move the
human out of the city (i.e., off the grid), then the human stays in the current cell.

RECRUIT. If a human survives for three-time steps, at the end of the time step (i.e., after all
humans have moved) the human recruits a new human into an adjacent empty space. This is
simulated by creating a new human in an adjacent (up, down, left, or right – i.e., diagonal not
allowed) cell that is empty. If there is no empty cell available, no recruiting occurs. Once a
recruit is produced, a human cannot recruit again until it has survived three more steps. If
humans are still alive and are unable to recruit (i.e., are surrounded by zombies and or edges)
their recruit counter should be re-set to zero.

The zombies behave according to the following rules (in order):
MOVE/EAT. For every time step, the zombie moves to an adjacent cell (diagonal allowed)
containing a human and eat the human. If there are no humans in adjoining cells, the zombie
moves according to the same rules as the human. Note that a zombie cannot eat other zombies.

CONVERT. If a zombie survives for eight-time steps, (and after all zombies have moved) it
converts a randomly selected existing adjacent (i.e. including diagonal) human into a zombie. If
zombies are still alive and are unable to convert, their convert counter should retain a state so
that they convert a human provided the very next opportunity.

STARVE. If the zombie has not eaten any humans within three-time steps, at the end of the third
time step the virus will lose its hold and the zombie converts to a human (i.e. replace the
zombie with a new human).

The project implements this simulation and draw the city grid using ASCII characters of ‘O’ for a human
and ‘X’ for a zombie. Creates a class named Organism that encapsulates basic data common to all
humans and zombies. This class has a virtual function named ‘move’ that is defined in the derived (aka
sub) classes of Human and Zombie.
