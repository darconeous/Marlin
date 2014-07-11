

#ifndef __FASTSQRT_H__
#define __FASTSQRT_H__ 1


static inline float
fastsqrt_inv(float x)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;
//#define FASTSQRT_MAGIC	(0x5f3759df)
#define FASTSQRT_MAGIC	(0x5f375a86)

	x2 = x * 0.5F;
	y  = x;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//      y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

	return y;
}

static inline float
fastsqrt(float x)
{
	return 1.0f/fastsqrt_inv(x);
}

#endif
