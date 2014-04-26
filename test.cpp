#ifdef __WAND__
target[name[mathext_test] type[application]]
#endif

#include "ode.h"
#include <cstdio>

void print(double x,double t)
	{
	printf("%.15g\t%.15g\n",t,x);
	}
	
class FuncObj
	{
	public:
		typedef double StateType;
		
		StateType operator()(StateType x,double t)
			{
			return x;
			}
	};

class FuncJacobi
	{
	public:
		double operator()(double x,double t)
			{return 1;}
	};

int main()
	{
	double t_0=0;
	double x_0=1;
	size_t N=16;
	double dt=1.0/N;
	FuncObj foo;
	FuncJacobi foo_deriv;
	MathExt::ODE::trapets(foo,x_0,t_0,dt,N,foo_deriv,print);
	}
