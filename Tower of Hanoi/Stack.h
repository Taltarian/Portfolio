
#include <vector>

#ifndef STACK_H
#define STACK_H

class Stack
{
private:
    //A vector has functionality perfect for a stack
    std::vector<int>  m_stacked;

public:
    //Constructors
    Stack();
    Stack(int size);

    //Check if stack is empty
    bool isEmpty();

    //Gets current size of stack
    int getSize();

    //Pushes value onto stack
    void pushTo(int newMember);

    //Pops off top value of stack
    int popFrom();

    //Reads top value of stack
    int topValue();

    //Reads value held at index in stack
    int readValue(int index);
};

#endif
