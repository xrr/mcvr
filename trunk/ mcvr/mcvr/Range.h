#pragma once
#include <iostream>

class Range
{
public:
	double lbound;
	double ubound;
	int steps;
	
	
	Range(double=0, double=500, int=5000);
	~Range(void);

	double Length(void);
	double StepSize(void);
	double* Bounds(void);
		
	//Can be iterated:
	double current; 
	double Next(void);
	void Reset(void);

	//To simplify output...:
	friend std::ostream& operator<< (std::ostream&, Range&);
};