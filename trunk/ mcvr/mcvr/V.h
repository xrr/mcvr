#pragma once
#include <iostream>
#include <gsl/gsl_vector.h>

class V
{
protected:
	gsl_vector* _pV;
	unsigned _size;
public:
	V(unsigned);
	~V(void);
	unsigned Size(void);
	double Get(unsigned);
	void Set(unsigned, double);
	double GetLast(void);
	void SetLast(double);
	friend std::ostream& operator<< (std::ostream&, V&);
	friend gsl_vector* operator<<(gsl_vector*, V&);
	friend V& operator<<(V&, gsl_vector*);
};
