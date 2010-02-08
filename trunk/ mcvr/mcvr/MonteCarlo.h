#pragma once
#include "BlackScholes.h"
#include "Range.h"
#include "Payoff.h"
#include "Call.h"

class MonteCarlo
{
	BlackScholes* _pBS;
	Range* _pR;
	Payoff* _pP;
public:
	MonteCarlo(BlackScholes* = new BlackScholes(), Range* = new Range(), Payoff* = new Call());
	~MonteCarlo(void);
	double Run(int=1);
};
