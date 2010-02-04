#include "MTGenerator.h"

MTGenerator::MTGenerator(void) {
	pMT = new MTRand();
}

MTGenerator::~MTGenerator(void)
{
	delete pMT;
}

double MTGenerator::Next() {
	return pMT->rand();
}
