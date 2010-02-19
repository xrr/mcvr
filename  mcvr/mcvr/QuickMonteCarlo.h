#pragma once
#include "MonteCarlo.h"
#include "Range.h"
#include "Lognormal.h"
#include "PathIndependantPayoff.h"
#include "Call.h"

class QuickMonteCarlo :
	public MonteCarlo
{
	Lognormal* _pL;
	PathIndependantPayoff* _pPIP;
public:
	QuickMonteCarlo(Range* = new Range(),
		Lognormal* = new Lognormal(),
		PathIndependantPayoff* = new Call());
	~QuickMonteCarlo(void);
	double Run(unsigned=1);
};
