#ifdef __WAND__
target[name[valuemap.h]type[include]]
#endif

#ifndef MATHEXT_VALUEMAP_H
#define MATHEXT_VALUEMAP_H

#include "interval.h"

namespace MathExt
	{
	template<class T>
	class ValueMap
		{
		public:
			virtual T forward(const T& x) const=0;
			virtual T backward(const T& y) const=0;
			virtual Interval<T> domain() const=0;
			virtual Interval<T> range() const=0;
		};
	}

#endif