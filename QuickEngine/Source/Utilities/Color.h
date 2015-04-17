#ifndef __COLOR_H__
#define __COLOR_H__

#include "MathUtil.h"

class CColor
{

private:

	float R;
	float G;
	float B;
	float A;

public:

	CColor (float r, float g, float b, float a) : R(r), G(g), B (b), A(a) {}

	CColor (float r, float g, float b) : R(r), G(g), B (b), A(1.0f) {}

	CColor operator +(CColor b)
	{
		return CColor (R + b.R, G + b.G, B + b.B, A + b.A);
	}

	CColor operator -(CColor b)
	{
		return CColor (R - b.R, G - b.G, B - b.B, A - b.A);
	}

	CColor operator *(CColor b)
	{
		return CColor (R * b.R, G * b.G, B * b.B, A * b.A);
	}

	CColor operator *(float b)
	{
		return CColor (R * b, G * b, B * b, A * b);
	}

	CColor operator /(float b)
	{
		return CColor (R / b, G / b, B / b, A / b);
	}

	bool operator ==(const CColor& rhs) const
	{
		return (R == rhs.R && G == rhs.G && B == rhs.B && A == rhs.A);
	}

	bool operator !=(const CColor& rhs) const
	{
		return (R != rhs.R || G != rhs.G || B != rhs.B || A != rhs.A);
	}

	SDL_Color GetColor() 
	{ 
		SDL_Color color = {R, G, B, A};
		return color;
	}

	float Grayscale() { return 0.299f * R + 0.587f * G + 0.114f * B; }

	float& operator [](unsigned int i)
	{
		switch(i)
		{
		case 0:
			{
				return R;
			}
		case 1:
			{
				return G;
			}
		case 2:
			{
				return B;
			}
		case 3:
			{
				return A;
			}
		}
	}

	static CColor Red() { return CColor(1.0f, 0.0f, 0.0f, 1.0f); };

	static CColor Green() { return CColor(0.0f, 1.0f, 0.0f, 1.0f); }

	static CColor Blue() { return CColor(0.0f, 0.0f, 1.0f, 1.0f); }

	static CColor White() { return CColor(1.0f, 1.0f, 1.0f, 1.0f); }

	static CColor Black() { return CColor(0.0f, 0.0f, 0.0f, 1.0f); }

	static CColor Yellow() { return CColor(1.0f, 0.921568632f, 0.0156862754f, 1.0f); }

	static CColor Cyan() { return CColor(0.0f, 1.0f, 1.0f, 1.0f); }

	static CColor Magenta() { return CColor(1.0f, 0.0f, 1.0f, 1.0f); }

	static CColor Gray() { return CColor(0.5f, 0.5f, 0.5f, 1.0f); }

	static CColor Grey() { return CColor(0.5f, 0.5f, 0.5f, 1.0f); }

	static CColor Clear() { return CColor(0.0f, 0.0f, 0.0f, 0.0f); }

	static CColor Lerp(CColor a, CColor b, float t)
	{
		t = QMath::Clamp01(t);
		return CColor (a.R + (b.R - a.R) * t, a.G + (b.G - a.G) * t, a.B + (b.B - a.B) * t, a.A + (b.A - a.A) * t);
	}

	static CColor Add(CColor a, CColor b)
	{
		return CColor (a.R + b.R, a.G + b.G, a.B + b.B, a.A + b.A);
	}

	static CColor Subtract(CColor a, CColor b)
	{
		return CColor (a.R - b.R, a.G - b.G, a.B - b.B, a.A - b.A);
	}

	static CColor Multiply(CColor a, CColor b)
	{
		return CColor (a.R * b.R, a.G * b.G, a.B * b.B, a.A * b.A);
	}

	static CColor Multiply(CColor a, float b)
	{
		return CColor (a.R * b, a.G * b, a.B * b, a.A * b);
	}

	static CColor Multiply(float b, CColor a)
	{
		return CColor (a.R * b, a.G * b, a.B * b, a.A * b);
	}

	static CColor Divide(CColor a, float b)
	{
		return CColor (a.R / b, a.G / b, a.B / b, a.A / b);
	}

	static bool Equals(const CColor& lhs, const CColor& rhs)
	{
		return (lhs.R == rhs.R && lhs.G == rhs.G && lhs.B == rhs.B && lhs.A == rhs.A);
	}
};

#endif//__COLOR_H__