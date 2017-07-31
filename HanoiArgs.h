#pragma once
#ifndef HANOIARGS_H
#define HANOIARGS_H

class HanoiArgs
{
private:
	long int m_args[1];
	
public:
	void checkNargs(int nargs);

	void checkValue(long int arg);

	long int checkArgs(int nargs, const char *argv[]);

	void setNDisks(long int nDisks);

	long int getNDisks();

	HanoiArgs();
	HanoiArgs(int nargs, const char *argv[]);
};

#endif
