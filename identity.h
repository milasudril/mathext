#ifdef __WAND__
target[name[identity.h] type[include]]
#endif

#ifndef MATHEXT_IDENTITY_H
#define MATHEXT_IDENTITY_H

namespace MathExt
	{
	template<class T>
	T identity();
	
	template<>
	inline double identity()
		{return 1.0;}
	}

#endif
