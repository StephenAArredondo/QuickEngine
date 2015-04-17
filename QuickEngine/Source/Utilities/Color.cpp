#include "Math.h"
#include "MathUtil.h"

QColor::QColor(float r, float g, float b, float a) : R(r), G(g), B(b), A(a) {}

QColor::QColor(float r, float g, float b) : R(r), G(g), B(b), A(1.0f) {}

QColor QColor::operator+(QColor b)
{
	return QColor(R + b.R, G + b.G, B + b.B, A + b.A);
}

QColor QColor::operator-(QColor b)
{
	return QColor(R - b.R, G - b.G, B - b.B, A - b.A);
}

QColor QColor::operator*(QColor b)
{
	return QColor(R * b.R, G * b.G, B * b.B, A * b.A);
}

QColor QColor::operator*(float b)
{
	return QColor(R * b, G * b, B * b, A * b);
}

QColor QColor::operator/(float b)
{
	return QColor(R / b, G / b, B / b, A / b);
}

bool QColor::operator==(const QColor& rhs) const
{
	return (R == rhs.R && G == rhs.G && B == rhs.B && A == rhs.A);
}

bool QColor::operator!=(const QColor& rhs) const
{
	return (R != rhs.R || G != rhs.G || B != rhs.B || A != rhs.A);
}

float QColor::Grayscale() { return 0.299f * R + 0.587f * G + 0.114f * B; }

float QColor::operator[](unsigned int i)
{
	switch (i)
	{
		case 0:	return R;
		case 1: return G;
		case 2:	return B;
		case 3:	return A;
		default: return 0.0f;
	}
}

QColor QColor::Red() { return QColor(1.0f, 0.0f, 0.0f, 1.0f); };

QColor QColor::Green() { return QColor(0.0f, 1.0f, 0.0f, 1.0f); }

QColor QColor::Blue() { return QColor(0.0f, 0.0f, 1.0f, 1.0f); }

QColor QColor::White() { return QColor(1.0f, 1.0f, 1.0f, 1.0f); }

QColor QColor::Black() { return QColor(0.0f, 0.0f, 0.0f, 1.0f); }

QColor QColor::Yellow() { return QColor(1.0f, 0.921568632f, 0.0156862754f, 1.0f); }

QColor QColor::Cyan() { return QColor(0.0f, 1.0f, 1.0f, 1.0f); }

QColor QColor::Magenta() { return QColor(1.0f, 0.0f, 1.0f, 1.0f); }

QColor QColor::Gray() { return QColor(0.5f, 0.5f, 0.5f, 1.0f); }

QColor QColor::Grey() { return QColor(0.5f, 0.5f, 0.5f, 1.0f); }

QColor QColor::Clear() { return QColor(0.0f, 0.0f, 0.0f, 0.0f); }

QColor QColor::Lerp(QColor a, QColor b, float t)
{
	t = QMath::Clamp01(t);
	return QColor(a.R + (b.R - a.R) * t, a.G + (b.G - a.G) * t, a.B + (b.B - a.B) * t, a.A + (b.A - a.A) * t);
}

QColor QColor::Add(QColor a, QColor b)
{
	return QColor(a.R + b.R, a.G + b.G, a.B + b.B, a.A + b.A);
}

QColor QColor::Subtract(QColor a, QColor b)
{
	return QColor(a.R - b.R, a.G - b.G, a.B - b.B, a.A - b.A);
}

QColor QColor::Multiply(QColor a, QColor b)
{
	return QColor(a.R * b.R, a.G * b.G, a.B * b.B, a.A * b.A);
}

QColor QColor::Multiply(QColor a, float b)
{
	return QColor(a.R * b, a.G * b, a.B * b, a.A * b);
}

QColor QColor::Multiply(float b, QColor a)
{
	return QColor(a.R * b, a.G * b, a.B * b, a.A * b);
}

QColor QColor::Divide(QColor a, float b)
{
	return QColor(a.R / b, a.G / b, a.B / b, a.A / b);
}

bool QColor::Equals(const QColor& lhs, const QColor& rhs)
{
	return (lhs.R == rhs.R && lhs.G == rhs.G && lhs.B == rhs.B && lhs.A == rhs.A);
}