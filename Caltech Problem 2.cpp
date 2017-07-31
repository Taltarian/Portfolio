#include "stdafx.h"
#include "HanoiArgs.h"
#include "Hanoi.h"

int main(int argc, const char *argv[])
{
	HanoiArgs Disks(argc, argv);

	Hanoi Tower(Disks.getNDisks());

	Tower.solve();

    return 0;
}