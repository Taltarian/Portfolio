#include "Hanoi.h"
#include <iostream>

//Default Constructor sets number of disks to 1
//Fills peg A as that is starting peg
Hanoi::Hanoi()
{
    m_disks = 1;
    fillPeg(pegA);
}

//Sets m_disks to requested starting disks
Hanoi::Hanoi(long int size)
{
    m_disks = size;
    fillPeg(pegA);
}

//Fill peg with successively smaller disks
void Hanoi::fillPeg(Stack &peg)
{
    for (int value = m_disks; value > 0; --value)
    {
        peg.pushTo(value);
    }
}

//Executive function to fully solve Tower
void Hanoi::solve()
{
    moveStack(pegA, pegB, pegC, m_disks);
}

//Recursive function to move stack of size ndisks from origin to destination
void Hanoi::moveStack(Stack &origin, Stack &destination, Stack &spare, int nDisks)
{
    try
    {
        //Detects if Base case skipped
        if (nDisks <= 0)
            throw nDisks;
    }

    catch (int nDisks)
    {
        std::cerr << "Invalid number of disks attempted to move\n";
        exit(EXIT_FAILURE);
    }

    //Base Case
    if (nDisks == 1)
    {
        move(origin, destination);
        return;
    }

    //Recursive Implementation
    else
    {
        moveStack(origin, spare, destination, nDisks - 1);
        move(origin, destination);
        moveStack(spare, destination, origin, nDisks - 1);
    }

    return;

}

//Moves top of origin to top of destination
void Hanoi::move(Stack &origin, Stack &destination)
{
    //Displays state of Tower before move
    display();

    try
    {
        //If destination is empty, skip checking destination
        if (!destination.isEmpty())
        {
        //Prevents moving larger disk onto smaller disk
            if (origin.topValue() > destination.topValue())
            {
                throw "Attempted to move larger disk onto smaller disk";
            }
      
        //Prevents moving disk onto same disk
            if (destination.topValue() == origin.topValue())
            {
                throw "Disk duplication detected";
            }
        }
    }
    catch (const char *error)
    {
        std::cerr << "ILLEGAL MOVE: " << error << "\n";
        exit(EXIT_FAILURE);
    }

    //Uses push and pop functions to interact with stack
    destination.pushTo(origin.popFrom());

    //Displays state of tower after move
    display();
}

//Prints status of every peg
void Hanoi::display()
{
    std::cout << "A: ";
    pegStatus(pegA);

    std::cout << "B: ";
    pegStatus(pegB);

    std::cout << "C: ";
    pegStatus(pegC);

    std::cout << '\n';
}

void Hanoi::pegStatus(Stack &peg)
{
    //Prints each member of peg
    for (int entry = 0; entry < peg.getSize(); ++entry)
    {
        std::cout << " " << peg.readValue(entry);
    }
    std::cout << '\n';
}

