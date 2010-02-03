#pragma once

class Density
{
private:
	double* _Parameters;
public:
	Density(double*);
	~Density(void);
	virtual double Eval(double=0)=0;
};
