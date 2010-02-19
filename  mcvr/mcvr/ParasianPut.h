#pragma once
#include "Payoff.h"

class ParasianPut :
	public Payoff
{
public:
	double K, B, L;
	ParasianPut(double=90, double=70, double=50);
	~ParasianPut(void);
	double operator()(Trajectory*);
};