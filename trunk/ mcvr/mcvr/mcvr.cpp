#include <iostream>
#include <vector>

#include "Range.h"
#include "Density.h"
//#include "RandomGenerator.h"
//#include "LCGenerator.h"
//#include "MersenneTwister.h"

#include <gsl/gsl_math.h>

template <class Functor> 
double doubleoperation(Functor f, double d) {return f(f(d));}

int main() {
	/*
	RandomGenerator* pRG = new MersenneTwister();
	for(int i=0;i<20;i++) { std::cout << pRG->Nextdouble() << std::endl;
	*/


	class D1Functor {
	public: double operator()(double d) {return(-2*d);}
	};
	
	D1Functor d1;

	std::cout <<  doubleoperation(d1, 3) << std::endl;

	return 0;
}