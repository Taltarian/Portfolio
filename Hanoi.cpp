#include "Hanoi.h"
#include <iostream>
#include "stdafx.h"


void Hanoi::move(Stack origin, Stack destination)
{
	display();
	try 
	{
		if (destination.topValue > origin.topValue)
		{
			throw "Attempted to move larger disk onto smaller disk";
		}
		if (destination.topValue > origin.topValue)
		{
			throw "Disk duplication detected";
		}
	}
	catch (const char *error)
	{
		std::cerr << "ILLEGAL MOVE: " << error << "\n";
		exit(EXIT_FAILURE);
	}

	destination.pushTo(origin.popFrom);	
	display();
}

void Hanoi::moveStack(Stack origin, Stack destination, Stack spare, int nDisks)
{
	try
	{
		if (nDisks <= 0)
			throw nDisks;
	}

	catch (int nDisks)
	{
		std::cerr << "Invalid number of disks attempted to move\n";
		exit(EXIT_FAILURE);
	}

	if (nDisks == 1)
		move(origin, destination);

	else
	{
		moveStack(origin, spare, destination, nDisks - 1);
		move(origin, destination);
		moveStack(spare, destination, origin, nDisks - 1);
	}



}

void Hanoi::solve()
{
	moveStack(pegA, pegB, pegC, m_size);
}

void Hanoi::pegStatus(Stack peg)
{
	for (int entry = 0; entry < m_size; ++entry)
	{
		std::cout << " " << peg.readValue(entry);
	}
	std::cout << '\n';
}

void Hanoi::display()
{
	std::cout << "A: ";
	pegStatus(pegA);

	std::cout << "B: ";
	pegStatus(pegB);

	std::cout << "C: ";
	pegStatus(pegC);
}

void Hanoi::fillPeg(Stack peg)
{
	for (int value = 1; value <= m_size; ++value)
	{
		peg.pushTo(value);
	}
}

Hanoi::Hanoi()
{
	m_size = 1;
	fillPeg(pegA);
	fillPeg(pegB);
	fillPeg(pegC);
}

Hanoi::Hanoi(long int size)
{
	m_size = size;
	Stack pegA(m_size);
	Stack pegB(m_size);
	Stack pegC(m_size);

	fillPeg(pegA);
	fillPeg(pegB);
	fillPeg(pegC);
}