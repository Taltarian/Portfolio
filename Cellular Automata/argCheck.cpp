#include <iostream>
#include <string>
#include <stdlib.h>
#include <climits>
#include <string.h>
//function to check range and number of arguments
void argCheck(int nargs, long int args[])
{
    try
    {

        //Ensures number of arguments(not including command) is 6
        if (nargs != 7) 
        {
            //(nargs - 1) is the number of arguments excluding command name
            throw nargs - 1;
            
        }

        //Checks arguments lie within proper range
        //6 is the proper number of arguments for this program
    for (int iii = 0; iii < 6; ++iii) 
        {
            //All arguments must be positive
            if (args[iii] < 0)
            {
                throw "Please ensure all arguments are positive";
            }

            //Update rules have to be 1's and 0's
            //Values below 1 are already checked in above if statement
            if (iii > 1 && args[iii] > 1) 
            {
                throw "Please ensure update rule arguments are 1's or 0's";
            }
        }
    }

    catch(int n)
    {
        std::cerr << "Incorrect number of arguments."
        << "Expected number of arguments: 6, Supplied Arguments: " << n << "\n";

        exit(EXIT_FAILURE);
    }

    catch(const char* error)
    {
        std::cerr << "ERROR: " << error << "\n";
        exit(EXIT_FAILURE);
    }


}

//Function that converts arguments to ints and checks their validity
void convertCheckArgs(char *argv[], long int args[], int nargs)
{
    

    //iterates through arguments, converts to int, and stores in args[]
    //argv index starts at 1, because index 0 is command name
    try
    {
        for (int iii = 1, jjj = 0; iii < nargs; ++iii, ++jjj)
        {
            //Initalize Pointer for strtol function
            char *next_char = NULL;


            //calls strtol function to convert entry to base 10 long
            //First non-numeric character is stored in next_char
            args[jjj] = strtol (argv[iii],&next_char,10);
           
            //Ensures array is of reasonable size
            //Prevents program from asking for too much memory for arrays
            //Negative large sizes are checked in argCheck function
            if (args[jjj] > 1e7)
            {
                throw args[jjj];
            }

            //if next_char is not empty, it means input was not integer
            else if (strcmp(next_char,""))
            {
                throw "Improper Data Type, "
                "please ensure all arguments are of type int";
            }
        }
    }

    catch(long int size)
    {
        std::cerr << "ERROR: Very Large Input, program ended to prevent"
        " performance problems\n";
        exit(EXIT_FAILURE);
    }


    catch(const char* error)
    {
        std::cerr << "ERROR: " << error << "\n";
        exit(EXIT_FAILURE);
    }

    argCheck(nargs, args); //checks the number and range of args
}
