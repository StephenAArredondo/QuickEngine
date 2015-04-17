#ifndef __COLOR_H__
#define __COLOR_H__

struct QColor
{
	float R;
	float G;
	float B;
	float A;

	QColor(float r, float g, float b, float a);

	QColor(float r, float g, float b);

	QColor operator+(QColor b);

	QColor operator-(QColor b);
	
	QColor operator*(QColor b);

	QColor operator*(float b);

	QColor operator/(float b);

	bool operator==(const QColor& rhs) const;

	bool operator!=(const QColor& rhs) const;

	float Grayscale();

	float operator[](unsigned int i);

	static QColor Red();

	static QColor Green();

	static QColor Blue();

	static QColor White();

	static QColor Black();

	static QColor Yellow();

	static QColor Cyan();

	static QColor Magenta();

	static QColor Gray();

	static QColor Grey();

	static QColor Clear();

	static QColor Lerp(QColor a, QColor b, float t);

	static QColor Add(QColor a, QColor b);

	static QColor Subtract(QColor a, QColor b);

	static QColor Multiply(QColor a, QColor b);

	static QColor Multiply(QColor a, float b);

	static QColor Multiply(float b, QColor a);

	static QColor Divide(QColor a, float b);

	static bool Equals(const QColor& lhs, const QColor& rhs);
};

#endif//__COLOR_H__