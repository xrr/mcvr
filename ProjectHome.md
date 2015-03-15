Financial assets are simulated using Black-Scholes model :

- lognormality is assumed and only value at maturity is randomly drawn
(only for path-independant payoffs)

or

- stochastic differential equation is used to simulate complete process step by step
(slower but necessary for path-dependant payoffs)


Different options can be priced: {call, put}x{vanilla, lookback, parisian, parasian}. Random values are computed multiple times to obtain a mean value and an experimental standard deviation.


Everything is coded in C++ using object oriented programming principles.

The main program exports its results on the standard output or in a file but a simple R script is given to visualize quickly some outputs. In addition, to change parameters you must essentially modify it in source code and compile : Visual Studio have been used but everything else should be ok, maybe with minor changes. There is no dependencies excepted with CRT, no libraries are required except standard one.




(As the project name indicates, the original purpose of the project was to implement variance reduction methods including importance sampling but it is not here for the moment and will maybe never be.)