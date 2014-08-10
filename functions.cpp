#ifdef __WAND__
target[name[functions.o] type[object]]
#endif

#include "functions.h"
#include <cmath>
#include <utility>

namespace
	{
	constexpr unsigned int lengthMirror(unsigned int N)
		{return 2*N;}

	constexpr unsigned int indexMirror(int value,unsigned int N)
		{return value + N;}

	constexpr int valueMirror(int index,unsigned int N)
		{return index - N;}

	class Lookup
		{
		public:
			Lookup()
				{
				for(unsigned int k=0;k<lengthMirror(N);++k)
					{
					auto v=valueMirror(k,N);

					values[k].first=std::exp2(float(v)/N);
					values[k].second=std::exp2(float(v+1)/N) - values[k].first;
					}
				}

			float operator()(float r) const
				{
				int v_0=floor(N*r);
				unsigned int i_0=indexMirror(v_0,N);

				return values[i_0].first + values[i_0].second*(N*r - v_0);
				}

		private:
			static constexpr unsigned int N=24;
			std::pair<float,float> values[lengthMirror(N)];
		};

	const Lookup table;
	}

float MathExt::exp2_fast(float x)
	{
	float i_part;
	auto r=std::modf(x, &i_part);
	auto xi=table(r);
	int i_part_int=i_part;
	unsigned int* ixi=(unsigned int*)( &xi);
	*ixi+=i_part_int<<23;
	return *((float*)ixi);
	}