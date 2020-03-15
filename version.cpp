#include <iostream>
#include "version.h"

using namespace std;

extern double *versionPtr;

void displayVersion()
{
	std::cout<<"Current version is "<<*versionPtr<<".";
}

