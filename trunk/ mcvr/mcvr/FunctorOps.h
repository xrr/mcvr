#pragma once

template <class Functor>
double apply(Functor f, double d) {return f(d);}

template <class Functor> 
double apply2x(Functor f, double d) {return f(f(d));}