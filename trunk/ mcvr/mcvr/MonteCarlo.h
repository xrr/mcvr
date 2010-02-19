#pragma once
#include "Range.h"
#include "BlackScholes.h"
#include "BlackScholesSDE.h"
#include "Payoff.h"
#include "ParisianCall.h"

class MonteCarlo
{
protected:
	Range* _pR;
	BlackScholes* _pBS;
	Payoff* _pP;
public:
	MonteCarlo(Range* = new Range(),
		BlackScholes* = new BlackScholesSDE(),
		Payoff* = new ParisianCall());
	~MonteCarlo(void);
	virtual double Run(unsigned=1);
};
