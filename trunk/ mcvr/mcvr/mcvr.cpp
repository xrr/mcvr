#include <iostream>

#include "RandomGenerator.h"
#include "LCGenerator.h"
#include "MersenneTwister.h"

int main() {

	RandomGenerator* pRG = new MersenneTwister();
	for(int i=0;i<20;i++) { std::cout << pRG->Nextdouble() << std::endl; }

	return 0;
}