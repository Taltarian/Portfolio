
#include "Stack.h"
#ifndef HANOI_H
#define HANOI_h

class Hanoi
{
private:
    //Member variable to hold number of starting disks
    long int m_disks;

    //Each peg is a Stack objects
    Stack pegA;
    Stack pegB;
    Stack pegC;

public:
    //Constructors
    Hanoi();
    Hanoi(long int size);

    //Fills peg with starting number of disks
    void fillPeg(Stack &peg);

    //Solves Hanoi tower and prints out each move
    void solve();

    //Moves an entire stack of size nDisks from origin peg to destination peg
    //Uses Spare peg for recursion
    void moveStack(Stack &origin, Stack &destination, Stack &spare, int nDisks);

    //Function to move top disk from origin peg to destination peg
    void move(Stack &origin, Stack &destination);

    //Prints out state of every peg
    void display();

    //Prints out current state of peg
    void pegStatus(Stack &peg);
};

#endif
