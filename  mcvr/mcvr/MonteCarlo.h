#pragma once
#include "Range.h"
#include "RandomGenerator.h"
#include "MTGenerator.h"

template<class Functor>
class MonteCarlo
{
	Functor _f;
	Range _r;
	RandomGenerator* _pRG;
	double _result;
public:
	MonteCarlo(Functor, Range, RandomGenerator* = new MTGenerator());
	~MonteCarlo(void);
	Range GetRange(void);
	void RunSim(int);
	double GetResult(void);
	
};

template<class Functor>
MonteCarlo<Functor>::MonteCarlo(Functor f, Range r, RandomGenerator* pRG) : _f(f), _r(r), _pRG(pRG), _result(0) {}

template<class Functor>
MonteCarlo<Functor>::~MonteCarlo(void) {}

template<class Functor>
Range MonteCarlo<Functor>::GetRange(void) {
	return _r;
}

template<class Functor>
void MonteCarlo<Functor>::RunSim(int n) {
	_result += 3.14*n;
}

template<class Functor>
double MonteCarlo<Functor>::GetResult(void) {
	return _result;
}