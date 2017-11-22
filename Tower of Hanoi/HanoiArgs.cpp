#include "HanoiArgs.h"
#include <iostream>
#include <string.h>
#include <climits>

//Default Constructor sets number of disks to 1
HanoiArgs::HanoiArgs()
{
    m_args[0] = 1;
}

//Constructor checks argument and if valid passes it to member array
HanoiArgs::HanoiArgs(int nargs, const char *argv[])
{
    m_args[0] =  checkArgs(nargs, argv) ;
}

//Ensures user input 1 argument
void HanoiArgs::checkNargs(int nargs)
{
    try
    {
        //Checks against 2 because program name counts as 1 argument
        if (nargs != 2)
        {
            throw nargs;
        }
    }

    catch (int nargs)
    {
        std::cerr << "Error: Expected 1 argument, " << nargs << " provided.";
        exit(EXIT_FAILURE);
    }
}

//Ensures valid value for number of disks
void HanoiArgs::checkValue(long int arg)
{
    try
    {
        //Must be positive number of disks
        if (arg <= 0)
        {
            throw arg;
        }

        //Excesively large inputs cause instability
        if (arg > 10000)
        {
            throw 10000;
        }
    }

    catch (long int value)
    {
        std::cerr << "ERROR: Please ensure argument is positive\n";
        exit(EXIT_FAILURE);
    }

    catch (const int size)
    {
        std::cerr << "ERROR: Argument too large, please "
            "ensure argument is less than " << size << '\n';
        exit(EXIT_FAILURE);
    }
}

//Function to convert argument and checks its validity
long int HanoiArgs::checkArgs(int nargs, const char *argv[])
{
    //Dummy Variable to hold converted value;
    long int arg = 0;

    //Ensure proper number of arguments
    checkNargs(nargs);

    //Char to hold character after numeric value in argv
    char *next_char = NULL;

    //Perform conversion
    arg = strtol(argv[1], &next_char, 10);
    try
    {
        //If character is not empty, than non-integer was input
        if (strcmp(next_char, ""))
        {
            throw "Improper Data type. Please ensure argument is type long int";
        }
    }

    catch (const char *error)
    {

        std::cerr << "ERROR: " << error << '\n';
        exit(EXIT_FAILURE);
    }

    //Check that arg has valid value
    checkValue(arg);

    //If Valid, arg is returned
    return arg;
}

//Sets Number of disks held by object
void HanoiArgs::setNDisks(long int nDisks)
{
    checkValue(nDisks);
    m_args[0] = nDisks;
}

//Returns number of disks held by object
long int HanoiArgs::getNDisks()
{
    return m_args[0];
}
