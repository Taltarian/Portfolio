#include "Stack.h"
#include <iostream>

//default constructor starts stack empty
Stack::Stack()
{
    m_stacked.resize(0,0);
}

//Fills stack with zeros
Stack::Stack(int size)
{
    m_stacked.resize(size,0);
}

//Checks if stack is empty
bool Stack::isEmpty()
{
    return m_stacked.empty();
}

//Returns size of stack
int Stack::getSize()
{
    return m_stacked.size();
}

//Pushes new value onto stack
void Stack::pushTo(int newMember)
{
    m_stacked.push_back(newMember);
}

//Returns top value of stack and pops it off
int Stack::popFrom()
{
    try
    {
    //throws error if empty stack
    if (m_stacked.empty())
        throw m_stacked.empty();
    }

    catch (bool empty)
    {
        std::cerr << "Attempted to read from empty stack\n";
        exit(EXIT_FAILURE);
    }

    int top = m_stacked.back();
    m_stacked.pop_back();
    return top;
}

//Returns top value of stack
int Stack::topValue()
{
    try
    {
    //throws error if empty stack
    if (m_stacked.empty())
        throw m_stacked.empty();
    }

    catch (bool empty)
    {
        std::cerr << "Attempted to read from empty stack\n";
        exit(EXIT_FAILURE);
    }

    return m_stacked.back();
}

//Reads value at entry
int Stack::readValue(int index)
{
    try
    {
        return m_stacked.at(index);
    }
    
    //Checks if attempted to access stack out of range
    catch(const std::out_of_range error)
    {
        std::cerr << "Attempted to access invalid entry in stack\n";
        exit(EXIT_FAILURE);
    }
}
