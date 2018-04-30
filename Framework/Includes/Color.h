#ifndef COLOR_H
#define COLOR_H

class Color
{
public:
	Color(float r, float g, float b, float a) { this->r = r; this->g = g; this->b = b; this->a = a; }
	float r, g, b, a;
};

class Color_Black : public Color
{
public:
	Color_Black() : Color(0.0f, 0.0f, 0.0f, 1.0f) {}
	float r, g, b, a;
};

class Color_White : public Color
{
public:
	Color_White() : Color(1.0, 1.0, 1.0, 1.0f) {}
	float r, g, b, a;
};

class Color_Green : public Color
{
public:
	Color_Green() : Color(0.0f, 1.0f, 0.0f, 1.0f) {}
	float r, g, b, a;
};

class Color_LimeGreen : public Color
{
public:
	Color_LimeGreen() : Color(0.205f, 0.705f, 0.205f, 1.0f) {}
	float r, g, b, a;
};

#endif // !COLOR_H