#include "mlx/mlx.h"

//changing the int value of each color to a binary value, then put it in the 
//Binary place for transparency, red, green and blue
//At the end it will give another it, which is not generated out of int operation, but from
//bitwise operation and this is the trick
int color_mix(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

//extarcting t
int get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

//extarcting r
int get_t(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

//extarcting g
int get_t(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

//extarcting b
int get_t(int trgb)
{
	return ((trgb) & 0xFF);
}

/*************************************************************************************
|Another method using the *(int)(unsigned char) as it's size is already 1 byte = 8 bits|
***************************************************************************************/

//broadcasting the array of unsigned char of 4 chars, to an int
//which will do the same math of the bitwise operation and more
//clean way to manipulate colors at the same time 
int another_color_mix(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return ((*(int)(unsigned char)[4]) {b, r, g, t});
}


int other_get_t(int trgb)
{
	return (unsigned char *)&trgb[3];
}


int other_get_r(int trgb)
{
	return (unsigned char *)&trgb[2];
}

int other_get_g(int trgb)
{
	return (unsigned char *)&trgb[1];
}

int other_get_b(int trgb)
{
	return (unsigned char *)&trgb[0];
}

int add_shade(trgb, shade)
{
	return ((*(int)(unsigned char)[4]) {b - (b * shade), r - (r * shade), g - (g * shade), t - (t * shade)});
}

