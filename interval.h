#ifdef __WAND__
target[name[interval.h] type[include]
#endif

#ifndef MATHEXT_INTERVAL_H
#define MATHEXT_INTERVAL_H

namespace MathExt
	{
	template<class T>
	class Interval
		{
		public:
			Interval(T lower,T higher):m_lower(lower),m_higher(higher){}
			
			T m_lower;
			T m_higher;
		};

	template<class T>
	bool operator<(const T& x,const Interval<T>& i)
		{
		return x>i.m_lower && x<i.m_higher;
		}

	template<class T>
	bool operator>(const T& x,const Interval<T>& i)
		{
		return x<i.m_lower || x>i.m_higher;
		}

	template<class T>
	bool operator<=(const T& x,const Interval<T>& i)
		{
		return !(x>i);
		}

	template<class T>
	bool operator>=(const T& x,const Interval<T>& i)
		{
		return !(x<i);
		}
	}

#endif
