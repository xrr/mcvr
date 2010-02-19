#pragma once
#include "Payoff.h"

class ParasianCall :
	public Payoff
{
public:
	double K, B, L;
	ParasianCall(double=110, double=130, double=50);
	~ParasianCall(void);
	double operator()(Trajectory*);
};