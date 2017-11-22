
#include "HanoiArgs.h"
#include "Hanoi.h"
#include <iostream>

int main(int argc, const char *argv[])
{
    //Set up Object to hold number of disks
    //Constructor also checks validity of arguments
    HanoiArgs Disks(argc, argv);

    //Initialize Hanoi Tower that starts with number of disks input
    Hanoi Tower(Disks.getNDisks());

    //Solves the tower of Hanoi, outputting each move
    Tower.solve();

    return 0;
}
