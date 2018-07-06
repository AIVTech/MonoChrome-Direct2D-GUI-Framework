#ifndef COLOR_H
#define COLOR_H

class Color
{
public:
	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) { this->r = r; this->g = g; this->b = b; this->a = a; }
	uint8_t r, g, b, a;
};

class Color_Black : public Color
{
public:
	Color_Black() : Color(0, 0, 0, 255) {}
	uint8_t r, g, b, a;
};

class Color_White : public Color
{
public:
	Color_White() : Color(255, 255, 255, 255) {}
	uint8_t r, g, b, a;
};

class Color_Green : public Color
{
public:
	Color_Green() : Color(0, 255, 0, 255) {}
	uint8_t r, g, b, a;
};

class Color_LimeGreen : public Color
{
public:
	Color_LimeGreen() : Color(50, 205, 50, 255) {}
	uint8_t r, g, b, a;
};

class Color_LightGray : public Color
{
public:
	Color_LightGray() : Color(180, 180, 180, 255) {}
	uint8_t r, g, b, a;
};

class Color_DarkGray : public Color
{
public:
	Color_DarkGray() : Color(60, 60, 60, 255) {}
	uint8_t r, g, b, a;
};



#endif // !COLOR_H