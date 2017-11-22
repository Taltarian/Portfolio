#include "arrayManip.h"
#include <iostream>

//Updates array according update rule via dummy array
void update(short array[], short dummy_array[], long int args[])
{
    //initalize variable to hold sum of cell and neighbors
    short sum{ 0 }; 

    //iterates through whole array
    for (int iii = 0; iii < args[0]; ++iii)
    {
        //Defines sum rules

        //For first cell, sum of first and second cell
        if (iii == 0) 
            sum = array[iii] + array[iii + 1];

        //For last cell, sum of last and second-to-last cell
        else if (iii == (args[0] - 1)) 
            sum = array[iii - 1] + array[iii];

        //For all other, sum of cell and its neighbors
        else 
            sum = array[iii - 1] + array[iii] + array[iii + 1];

        //stores new values in dummy_array[] according to update rules
        if (sum == 0)
            dummy_array[iii] = args[2];
        else if (sum == 1)
            dummy_array[iii] = args[3];
        else if (sum == 2)
            dummy_array[iii] = args[4];
        else if (sum == 3)
            dummy_array[iii] = args[5];
    
    }

    //copies dummy array into array
    copyArray(dummy_array, array, args[0]); 
}

//Prints current state of automaton all on one line
void printStatus(short array[], long int length)
{
    for (int iii = 0; iii < length; ++iii)
    {
        std::cout << array[iii];
    }
    std::cout << "\n";
}

//Updates and prints status requested number of times
void iterateUpdate(short array[], short dummy_array[], long int args[])
{
    for (int iii = 0; iii < args[1]; ++iii)
    {
        update(array, dummy_array, args);
        printStatus(array, args[0]);
    }
}
