#pragma once
#include <vector>

#ifndef STACK_H
#define STACK_H

class Stack
{
private:
	std::vector<int>  m_stacked;

public:
	bool isEmpty();

	void pushTo(int newMember);

	int popFrom();

	int topValue();

	int readValue(int index);

	Stack();
	Stack(int size);


};

#endif
