#include <iostream>
#include "MonteCarlo.h"
#include "RandomGenerator.h"

int main() {
	/*MonteCarlo MC;
	std::cout << "MC.Run: " << MC.Run() << std::endl;*/


	//RandomGenerator* pRG = new NormalGenerator();
	NormalGenerator* pRG = new NormalGenerator();
	for (int i=0; i<1000; i++) {
		std::cout /*<< "[" << i << "] "*/ << pRG->Next(3,1) << std::endl;
	}


	//system("pause");
	return 0;
}