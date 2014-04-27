#ifdef __WAND__
target[name[ode.h] type[include]]
#endif


#ifndef MATHEXT_ODE_H
#define MATHEXT_ODE_H

#include "identity.h"

#include <cstddef>
#include <cstdio>

namespace MathExt
	{
	namespace ODE
		{
 		template<class F>
		struct State
			{
			typedef typename F::StateType type;
			};
	
		template <class R, class... A>
		struct State<R(A...)>
			{
			typedef R type;
			};

		template<class ODEFunction>
		bool continue_always(const typename State<ODEFunction>::type& x_0
			,double t_0)
			{return 0;}
			
		template<class ODEFunction>
		void printer_null(const typename State<ODEFunction>::type& x_0,double t_0)
			{}
		
		template<class ODEFunction
			,class Printer=decltype(printer_null<ODEFunction>)
			,class StopCondition=decltype(continue_always<ODEFunction>)> 
		bool euler_fwd(ODEFunction& f,typename State<ODEFunction>::type& x_0
			,double t_0,double dt,size_t N_iter
			,Printer& printer=printer_null<ODEFunction>
			,StopCondition& cond=continue_always<ODEFunction>)
			{
			size_t k=0;
			while(N_iter)
				{
				if(cond(x_0,k*dt))
					{return 1;}
				printer(x_0,k*dt);
				x_0+=dt*f(x_0,k*dt);
				--N_iter;
				++k;
				}
			printer(x_0,k*dt);
			return 0;
			}
		
		template<class ODEFunction
			,class JacobiFunction
			,class Printer=decltype(printer_null<ODEFunction>)
			,class StopCondition=decltype(continue_always<ODEFunction>)> 
		bool euler_bwd(ODEFunction& f,typename State<ODEFunction>::type& x_0
			,double t_0,double dt,size_t N_iter,JacobiFunction& J
			,Printer& printer=printer_null<ODEFunction>
			,StopCondition& cond=continue_always<ODEFunction>)
			{
			size_t k=0;
			while(N_iter)
				{
				if(cond(x_0,k*dt))
					{return 1;}
				printer(x_0,k*dt);
				auto x_predicted=x_0+dt*f(x_0,k*dt);
	
			//	Use one Newton step to find an approximation to x_0
				x_0=x_predicted - (x_predicted - dt*f(x_predicted,(k+1)*dt) - x_0 )
					/(identity<typename State<ODEFunction>::type>() - dt*J(x_predicted,(k+1)*dt));
				--N_iter;
				++k;
				}
			printer(x_0,k*dt);
			return 0;
			}
		
		template<class ODEFunction
			,class JacobiFunction
			,class Printer=decltype(printer_null<ODEFunction>)
			,class StopCondition=decltype(continue_always<ODEFunction>)> 
		bool trapets(ODEFunction& f,typename State<ODEFunction>::type& x_0
			,double t_0,double dt,size_t N_iter,JacobiFunction& J
			,Printer& printer=printer_null<ODEFunction>
			,StopCondition& cond=continue_always<ODEFunction>)
			{
			size_t k=0;
			while(N_iter)
				{
				if(cond(x_0,k*dt))
					{return 1;}
				printer(x_0,k*dt);
				auto x_predicted=x_0+dt*f(x_0,k*dt);
	
			//	Use one Newton step to find an approximation to x_0
				x_0=x_predicted - (x_predicted - dt*f(x_predicted,(k+1)*dt) - x_0 )
					/(identity<typename State<ODEFunction>::type>() -dt*J(x_predicted,(k+1)*dt));
				
				x_0=0.5*(x_0 + x_predicted);
					
				--N_iter;
				++k;
				}
			printer(x_0,k*dt);
			return 0;
			} 
		}
	}

#endif
