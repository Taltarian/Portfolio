#pragma once
#include "Stack.h"
#ifndef HANOI_H
#define HANOI_h

class Hanoi
{
private:
	long int m_size;
	Stack pegA;
	Stack pegB;
	Stack pegC;

public:
	void move(Stack origin, Stack destination);
	void moveStack(Stack origin, Stack destination, Stack spare, int nDisks);
	void pegStatus(Stack peg);
	void display();
	void solve();
	void fillPeg(Stack peg);
	Hanoi();
	Hanoi(long int size);
};

#endif