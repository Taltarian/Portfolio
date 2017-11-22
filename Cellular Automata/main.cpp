

#include <iostream>
#include <random>
#include "arrayManip.h"
#include "argCheck.h"
#include "update.h"

int main(int argc, char *argv[])
{
    //Initalize array to hold int values of arguments
    long int *args = new long int[argc]();

    //Use function to ensure proper type and number of arguments
    //Then stores arguments as ints in args[]
    convertCheckArgs(argv, args, argc);


    //Initalize automaton as array and fill randomly with 1's and 0's
    short *automaton = new short[args[0]]();

    fillArray(args[0], automaton);


    //Initalize dummy array for calculations and copy automaton into it
    short *dummy_automaton = new short[args[0]]();
    copyArray(automaton, dummy_automaton, args[0]);

    //Print initial state of automaton
    printStatus(automaton, args[0]);

    //Updates automaton and prints result requested number of times
    iterateUpdate(automaton, dummy_automaton, args); 

    //deallocates dynamic arrays to prevent memory leaks
    delete[] automaton;
    delete[] dummy_automaton;

    return 0;
}

