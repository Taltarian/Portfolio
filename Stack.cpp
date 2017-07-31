#include "Stack.h"
#include <iostream>
#include "stdafx.h"

bool Stack::isEmpty()
{
	return m_stacked.empty();
}

void Stack::pushTo(int newMember)
{
	m_stacked.push_back(newMember);
}

int Stack::popFrom()
{
	int top = m_stacked.back();
	m_stacked.pop_back();
	return top;
}

int Stack::topValue()
{
	return m_stacked.back();
}

int Stack::readValue(int index)
{
	try
	{
		return m_stacked.at(index);
	}
	catch(const std::out_of_range error)
	{
		std::cerr << "Attempted to access invalid entry in stack\n";
		exit(EXIT_FAILURE);
	}
}

Stack::Stack()
{
	m_stacked.resize(1);
}

Stack::Stack(int size)
{
	m_stacked.resize(size);
}