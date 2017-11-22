
#ifndef HANOIARGS_H
#define HANOIARGS_H

class HanoiArgs
{
private:
    //Sets up Array to hold number of disks
    //Initialized as array to support possible new functionality
    long int m_args[1];

public:
    //Ensures user input 1 argument
    void checkNargs(int nargs);

    //Ensures no negative or excessively large values
    void checkValue(long int arg);

    //Checks validity of argument, and if valid returns it
    long int checkArgs(int nargs, const char *argv[]);

    //Sets number of disks stored by object (unused in program)
    void setNDisks(long int nDisks);

    //Returns number of disks stored by object
    long int getNDisks();

    HanoiArgs();
    HanoiArgs(int nargs, const char *argv[]);
};

#endif
