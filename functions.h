#ifdef __WAND__
target[name[functions.h] type[include]]
dependency[functions.o]
#endif

#ifndef MATHEXT_FUNCTIONS_H
#define MATHEXT_FUNCTIONS_H

namespace MathExt
	{
	template <class T> T sgn(T val)
		{return (T(0) < val) - (val < T(0));}

	template<class Distribution,class RandSource>
	auto rand(Distribution&& dist,RandSource& source) -> decltype(dist(source))
		{
		return dist(source);
		}

	float exp2_fast(float x);
	}

#endif
