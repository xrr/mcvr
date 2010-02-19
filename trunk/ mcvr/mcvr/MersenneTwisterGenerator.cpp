#include "MersenneTwisterGenerator.h"

MersenneTwisterGenerator::MersenneTwisterGenerator(void) {
	_pMTR = new MTRand();
}

MersenneTwisterGenerator::~MersenneTwisterGenerator(void)
{
	delete _pMTR;
}

double MersenneTwisterGenerator::Next(void) {
	return _pMTR->rand();
}
