#pragma once
#include "Payoff.h"

class ParisianCall :
	public Payoff
{
public:
	double K, B, L;
	//attention: unité de L = pas de temps de la trajectoire
	ParisianCall(double=110, double=130, double=50);
	~ParisianCall(void);
	double operator()(Trajectory*);
};