#pragma once
#include <iostream>
#include <vector>
//#include "gsl/gsl_vector.h"

class V {
protected:
	std::vector<double>* _pV;
	unsigned _size;
public:
	V(unsigned);
	~V(void);
	unsigned Size(void);
	double Get(unsigned);
	void Set(unsigned, double);
	double GetLast(void);
	void SetLast(double);
	void Push(double);
	void Reset(unsigned);
	friend std::vector<double>& operator>> (std::vector<double>&, V&);
	friend std::ostream& operator<< (std::ostream&, V&);
	friend std::istream& operator>> (std::istream&, V&);
	friend const char* operator>> (const char*, V&);

	V(const V& v);
	void swap(V&);
	V& operator= (V);

	/*
	friend std::ostream& operator<< (std::ostream&, gsl_vector*);
	friend gsl_vector* operator<< (gsl_vector*, V&);
	friend V& operator<< (V&, gsl_vector*);
	*/	
};