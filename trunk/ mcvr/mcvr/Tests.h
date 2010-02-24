#pragma once
#include "Payoff.h"

class Tests
{
public:

	static void VTest(void);
	static void SampleTest(void);
	// ==>
	static void BaseTests(void);

	static void LinearCongruentialGeneratorTest(unsigned=5000);
	static void MersenneTwisterGeneratorTest(unsigned=5000);
	static void BoxMullerGeneratorTest(unsigned=5000);
	static void MarsagliaGeneratorTest(unsigned=5000);
	static void MillionGaussSpeedTest(unsigned=100);
	// ==>
	static void RNGTests(void);

	static void LognormalTest(unsigned=5000);
	static void BlackScholesSDETest(void);
	// ==>
	static void BSTests(void);

	static void PayoffTest(Payoff*, const char*);
	// ==>
	static void PayoffTests(void);

	static void MonteCarloTest(void);
	//==>
	static void MCTests(void);

};
