#ifdef __WAND__
target[name[mathext_test] type[application]]
#endif

#include "ode.h"

#include <vector/vector2d.h>

#include <cstdio>

void print(const Vector::Vector2d<double>& v,double t)
	{
	printf("%.15g\t%.15g\t%.15g\n",t,v.x,v.y);
	}
	
class FuncObj
	{
	public:
		typedef Vector::Vector2d<double> StateType;
		
		StateType operator()(StateType v,double t)
			{
			return {-v.y,0.5*v.x};
			}
	};

class FuncJacobi
	{
	public:
		Vector::Matrix22<double> operator()(const Vector::Vector2d<double>& v,double t)
			{
			return {0,-1,1,0};
				
			}
	};

int main()
	{
	double t_0=0;
	Vector::Vector2d<double> v_0={1,0};
	size_t N=16;
	double dt=1.0/N;
	FuncObj foo;
	FuncJacobi foo_deriv;
	MathExt::ODE::trapets(foo,v_0,t_0,dt,16*N,foo_deriv,print);
/*	FuncJacobi foo_deriv;
	MathExt::ODE::trapets(foo,x_0,t_0,dt,N,foo_deriv,print);*/
	}
