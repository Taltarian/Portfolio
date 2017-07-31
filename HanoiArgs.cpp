#include "HanoiArgs.h"
#include <iostream>
#include "stdafx.h"
#include <climits>

HanoiArgs::HanoiArgs()
{
	long int m_args[1]{1};
}

HanoiArgs::HanoiArgs(int nargs, const char *argv[])
{
	long int m_args[1]{ checkArgs(nargs, argv) };
}

void HanoiArgs::checkNargs(int nargs)
{
	try
	{
		if (nargs != 2)
		{
			throw nargs;
		}
	}
	catch (int nargs)
	{
		std::cerr << "Error: Expected 1 argument, " << nargs << " provided.";
		exit(EXIT_FAILURE);
	}
}
void HanoiArgs::checkValue(long int arg)
{
	try 
	{
		if (arg <= 0)
		{
			throw arg;
		}

		if (arg = LONG_MAX)
		{
			throw sizeof(long int);
		}
	}

	catch (long int value)
	{
		std::cerr << "ERROR: Please ensure argument is positive\n";
	}

	catch (int size)
	{
		std::cerr << "ERROR: Argument too large, please"
			"ensure argument is less than " << size << " bytes\n";
	}
}
long int HanoiArgs::checkArgs(int nargs, const char *argv[])
{
	long int arg = 0;
	checkNargs(nargs);

	char *next_char = NULL;
	arg = strtol(argv[1], &next_char, 10);

	try 
	{
		if (!strcmp(next_char, ""))
		{
			throw "Improper Data type. Please ensure argument is of type long int";
		}

		checkValue(arg);
	}
	
	catch (const char *error)
	{
		std::cerr << "ERROR: " << error << '\n';
		exit(EXIT_FAILURE);
	}

	return arg;
}

void HanoiArgs::setNDisks(long int nDisks)
{
	checkValue(nDisks);
	m_args[0] = nDisks;
}

long int HanoiArgs::getNDisks()
{
	return m_args[0];
}