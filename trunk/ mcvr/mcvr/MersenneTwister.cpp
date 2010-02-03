#include "MersenneTwister.h"

MersenneTwister::MersenneTwister(void) {
	pMT = new MTRand();
}

MersenneTwister::~MersenneTwister(void)
{
	delete pMT;
}

double MersenneTwister::Nextdouble() {
	return pMT->rand();
}
