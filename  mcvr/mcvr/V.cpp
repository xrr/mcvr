#include "V.h"

V::V(unsigned size) : _size(size) {
	_pV = gsl_vector_alloc(_size);
}

V::~V(void) {
	gsl_vector_free(_pV);
}

unsigned V::Size(void) {
	return _size;
}

double V::Get(unsigned i) {
	return gsl_vector_get(_pV,i);
}

void V::Set(unsigned i, double v) {
	gsl_vector_set(_pV,i,v);
}

double V::GetLast(void) {
	return Get(_size-1);
}
void V::SetLast(double v) {
	Set(_size-1,v);
}

std::ostream& operator<<(std::ostream& flux, V& v) {
	for (unsigned i=0; i<v._size; i++) {
		flux << "#" << gsl_vector_get(v._pV,i) << std::endl;
	}
	return flux;
}

//warning: identical size is not checked!
gsl_vector* operator<<(gsl_vector* pV, V& v) {
	for (unsigned i=0; i<pV->size; i++) {
		gsl_vector_set(pV,i,gsl_vector_get(v._pV,i));
	}
	return pV;
}

V& operator<<(V& v, gsl_vector* pV) {
	for (unsigned i=0; i<v._size; i++) {
		gsl_vector_set(v._pV,i,gsl_vector_get(pV,i));
	}
	return v;
}
