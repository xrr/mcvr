#include "V.h"
#include <vector>
#include <fstream>
#include <algorithm> // std::swap

V::V(unsigned size) : _size(size) {
	_pV = new std::vector<double>(_size);
}

V::V(const V& v) :_size(v._size) {
	_pV = new std::vector<double>(_size);
	(*_pV) = (*v._pV);
}

V::~V(void) {
	delete _pV;
}

void V::swap(V& v) {
	//never fail
	std::swap(_pV, v._pV);
	std::swap(_size, v._size);
}

V& V::operator=(V v) {
	swap(v); // this <-> local.v
	return (*this);
}

unsigned V::Size(void) {
	return _size;
}

double V::Get(unsigned i) {
	return (*_pV)[i];
}

void V::Set(unsigned i, double v) {
	(*_pV)[i] = v;
}

double V::GetLast(void) {
	return Get(_size-1);
}

void V::SetLast(double v) {
	Set(_size-1,v);
}

void V::Push(double v) {
	_pV->push_back(v);
	_size++;
}

void V::Reset(unsigned size) {
	_size = size;
	delete _pV;
	_pV = new std::vector<double>(size);
}

std::vector<double>& operator>> (std::vector<double>& stdv, V& v) {
	for (unsigned i=0; i<v._size; i++)
		v.Set(i,stdv[i]);
	return stdv;
}

std::ostream& operator<< (std::ostream& flux, V& v) {
	for (unsigned i=0; i<v._size; i++)
		flux << (*v._pV)[i] << std::endl;
	return flux;
}

std::istream& operator>> (std::istream& flux, V& v) {
	double linebuf;
	std::vector<double> vbuf;
	while (flux >> linebuf)
		vbuf.push_back(linebuf);
	v.Reset(vbuf.size());
	vbuf >> v;
	return flux;
}

const char* operator>> (const char* c, V& v) {
	std::ifstream is(c);
	is >> v;
	return c;
}

/* deprecated (gsl_vector related)

#include "gsl/gsl_vector.h"

std::ostream& operator<<(std::ostream& flux, gsl_vector* pGSLV) {
for (unsigned i=0; i<pGSLV->size; i++)
flux << gsl_vector_get(pGSLV,i)<< std::endl;
return flux;
}

gsl_vector* operator<<(gsl_vector* pGSLV, V& v) {
for (unsigned i=0; i<pGSLV->size; i++) {
gsl_vector_set(pGSLV,i,(*v._pV)[i]);
}
return pGSLV;
}


V& operator<<(V& v, gsl_vector* pGSLV) {
for (unsigned i=0; i<v._size; i++)
(*v._pV)[i] = gsl_vector_get(pGSLV,i);
return v;
}
*/