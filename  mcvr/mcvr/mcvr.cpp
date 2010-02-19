#include "Pipe.h"
#include "UnitTests.h"
#include <iostream>

int main() {
	{Pipe p("Lognormal.txt");
	UnitTests::LognormalTest(10,1);}


	return 0;
}
