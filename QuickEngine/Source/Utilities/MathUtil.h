#ifndef __MATH_UTIL_H__
#define __MATH_UTIL_H__

#include <math.h>

//////////////////////////////////////////////////////////////////////////
// Forward Declarations
//////////////////////////////////////////////////////////////////////////
struct QVector2;
struct QVector3;
struct QVector4;
struct QMatrix;
struct QQuaternion;
struct QColor;

//////////////////////////////////////////////////////////////////////////
// Constants
//////////////////////////////////////////////////////////////////////////

#undef PI
#define PI			3.1415926535897932f
#define FLOAT_MAX	3.402823466e+38F

#define PI_INVERSE	0.31830988618f
#define PI_HALF		1.57079632679f
#define DEG2RAD		0.0174532924f
#define RAD2DEG		57.29578f
#define EPSILON		1.401298E-45f

struct QMath
{
	template<class T>
	static float DegreesToRadians(T const& degreeValue) 
	{ 
		return degreeValue * DEG2RAD; 
	}

	static double DegreesToRadians(double degreeValue) 
	{ 
		return degreeValue * DEG2RAD; 
	}

	template<class T>
	static float RadiansToDegrees(T const& radianValue)
	{ 
		return radianValue * RAD2DEG;
	}
	
	static double RadiansToDegrees(double radianValue)
	{ 
		return radianValue * RAD2DEG;
	}

	static float Sin(float f)
	{
		return sin(f);
	}
	static float Cos(float f)
	{
		return cos(f);
	}
	static float Tan(float f)
	{
		return tan(f);
	}
	static float Asin(float f)
	{
		return asin(f);
	}
	static float Acos(float f)
	{
		return acos(f);
	}
	static float Atan(float f)
	{
		return atan(f);
	}
	static float Atan2(float y, float x)
	{
		return atan2(y, x);
	}
	static float Sqrt(float f)
	{
		return sqrt(f);
	}
	static float Abs(float f)
	{
		return abs(f);
	}
	static int Abs(int value)
	{
		return (int)abs(value);
	}
	static float Min(float a, float b)
	{
		return (a >= b) ? b : a;
	}
	static float Min(float values[])
	{
		int num = sizeof(values) / sizeof(float);

		if (num == 0)
			return 0.0f;

		float num2 = values [0];

		for (int i = 1; i < num; i++)
		{
			if (values [i] < num2)
				num2 = values [i];
		}

		return num2;
	}
	static int Min(int a, int b)
	{
		return (a >= b) ? b : a;
	}
	static int Min(int values[])
	{
		int num = sizeof(values) / sizeof(int);

		if (num == 0)
			return 0;

		int num2 = values [0];

		for (int i = 1; i < num; i++)
		{
			if (values [i] < num2)
				num2 = values [i];
		}

		return num2;
	}
	static float Max(float a, float b)
	{
		return (a <= b) ? b : a;
	}
	static float Max(float values[])
	{
		int num = sizeof(values) / sizeof(float);

		if (num == 0)
			return 0.0f;

		float num2 = values [0];

		for (int i = 1; i < num; i++)
		{
			if (values [i] > num2)
				num2 = values [i];
		}

		return num2;
	}
	static int Max(int a, int b)
	{
		return (a <= b) ? b : a;
	}
	static int Max(int values[])
	{
		int num = sizeof(values) / sizeof(int);

		if (num == 0)
			return 0;

		int num2 = values [0];

		for (int i = 1; i < num; i++)
		{
			if (values [i] > num2)
				num2 = values [i];
		}

		return num2;
	}
	static float Pow(float f, float p)
	{
		return pow(f, p);
	}
	static float Exp(float power)
	{
		return exp(power);
	}
	// static float Log(float f, float p)
	// {
	// 	return logf(f, p);
	// }
	static float Log(float f)
	{
		return log(f);
	}
	// 	static float Log2(float f)
	// 	{
	// 		return log2(f);
	// 	}
	static float Ceil(float f)
	{
		return ceil(f);
	}
	static float Floor(float f)
	{
		return floor(f);
	}
	// static float Round(float f)
	// {
	// 	return round(f);
	// }
	static int CeilToInt(float f)
	{
		return (int)ceil(f);
	}
	static int FloorToInt(float f)
	{
		return (int)floor(f);
	}
	// static int RoundToInt(float f)
	// {
	// 	return (int)round(f);
	// }
	static float Sign(float f)
	{
		return (f < 0.0f) ? -1.0f : 1.0f;
	}
	static float Clamp(float value, float min, float max)
	{
		if(value < min)
			value = min;
		else
		{
			if(value > max)
				value = max;
		}

		return value;
	}
	static int Clamp(int value, int min, int max)
	{
		if(value < min)
			value = min;
		else
		{
			if(value > max)
				value = max;
		}

		return value;
	}
	static float Clamp01(float value)
	{
		if(value < 0.0f)
			return 0.0f;

		if(value > 1.0f)
			return 1.0f;

		return value;
	}
	static float Lerp(float from, float to, float t)
	{
		return from + (to - from) * Clamp01(t);
	}
	static float MoveTowards(float current, float target, float maxDelta)
	{
		if(Abs(target - current) <= maxDelta)
			return target;

		return current + Sign(target - current) * maxDelta;
	}
	static float SmoothStep(float from, float to, float t)
	{
		t = Clamp01(t);
		t = -2.0f * t * t * t + 3.0f * t * t;
		return to * t + from * (1.0f - t);
	}
	static float Gamma(float value, float absmax, float gamma)
	{
		bool flag = false;

		if(value < 0.0f)
			flag = true;

		float num = Abs(value);

		if(num > absmax)
			return (!flag) ? num : (-num);

		float num2 = Pow(num / absmax, gamma) * absmax;

		return (!flag) ? num2 : (-num2);
	}
	static float Repeat(float t, float length)
	{
		return t - Floor(t / length) * length;
	}
	static float LerpAngle(float a, float b, float t)
	{
		float num = Repeat(b - a, 360.0f);

		if(num > 180.0f)
			num -= 360.0f;

		return a + num * Clamp01(t);
	}
	static float InverseLerp (float from, float to, float value)
	{
		if(from < to)
		{
			if(value < from)
				return 0.0f;

			if (value > to)
				return 1.0f;

			value -= from;
			value /= to - from;
			return value;
		}
		else
		{
			if(from <= to)
				return 0.0f;

			if (value < to)
				return 1.0f;

			if (value > from)
				return 0.0f;

			return 1.0f - (value - to) / (from - to);
		}
	}
	static float DeltaAngle (float current, float target)
	{
		float num = Repeat(target - current, 360.0f);

		if (num > 180.0f)
			num -= 360.0f;

		return num;
	}
	static float MoveTowardsAngle (float current, float target, float maxDelta)
	{
		target = current + DeltaAngle(current, target);
		return MoveTowards(current, target, maxDelta);
	}
};

#endif//__MATH_UTIL_H__