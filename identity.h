#ifdef __WAND__
target[name[identity.h] type[include]]
#endif

#ifndef MATHEXT_IDENTITY_H
#define MATHEXT_IDENTITY_H

namespace MathExt
	{
	template <class T>
	class IdentityType;
	
	template<>
	class IdentityType<double>
		{
		public:
			typedef double type;
			
			operator type() const
				{return 1.0;}
		};
		
	template<class T>
	typename IdentityType<T>::type identity()
		{return IdentityType<T>();}
	}

#endif
