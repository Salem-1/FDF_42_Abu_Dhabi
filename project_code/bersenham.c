#include "fdf.h"

//you can do all the declartion later in one line as static int vars[6];
void plotLineLow(int *x_ys, void *addr, int *img_data)
 {
	// int dx;
	// int dy;
	// int yi;
	// int diff;
	// int	y;
	// int x;
	b_vars bers;

	bers.dx = x_ys[2] - x_ys[0];
    bers.dy = x_ys[3] - x_ys[1];
    bers.yi = 1;
    if (bers.dy < 0)
    {   
		bers.yi = -1;
        bers.dy = -bers.dy;
    }
    bers.diff = (2 * bers.dy) - bers.dx;
    bers.y = x_ys[1];
	bers.x = x_ys[0] - 1;
	while (++bers.x < x_ys[2])
	{
		x_ys[0] = bers.x ;
		x_ys[1] = bers.y;
        my_mlx_pixel_put(addr, x_ys, img_data);
        if (bers.diff > 0)
		{
            bers.y = bers.y + bers.yi;
            bers.diff = bers.diff + (2 * (bers.dy - bers.dx));
		}
		else
            bers.diff = bers.diff + 2 * bers.dy;
	}
 }

// x0, y0, x1, y1, color)
void plotLineHigh(int *x_ys, void *addr, int *img_data)
 {
	// int dx;
	// int dy;
	// int xi;
	// int D;
	// int	y;
	// int x;
	b_vars bers;

	bers.dx = x_ys[2] - x_ys[0];
    bers.dy = x_ys[3] - x_ys[1];
    bers.xi = 1;
    if (bers.dx < 0)
    {   bers.xi = -1;
        bers.dx = -bers.dx;
    }
    bers.diff = (2 * bers.dx) - bers.dy;
    bers.x = x_ys[0];
	bers.y = x_ys[1] - 1;
	while (++bers.y < x_ys[3])
	{
		//ft_printf(" y0 = %d, y1 = %d\n", y, x_ys[3]);
		x_ys[0] = bers.x;
		x_ys[1] = bers.y;
        my_mlx_pixel_put(addr, x_ys, img_data);
        if (bers.diff > 0)
		{
            bers.x = bers.x + bers.xi;
            bers.diff = bers.diff + (2 * (bers.dx - bers.dy));
		}
		else
            bers.diff = bers.diff + 2 * bers.dx;
	}
 }
void connect_dots(int *x_ys, void *addr, int *img_data)
{
    if (abs(x_ys[3] - x_ys[1]) < abs(x_ys[2] - x_ys[0]))
    {   
		if (x_ys[0] > x_ys[2])
		{
			ft_swap(&x_ys[0], &x_ys[2]);
			ft_swap(&x_ys[1], &x_ys[3]);
            plotLineLow(x_ys, addr, img_data);
		}
		else
            plotLineLow(x_ys, addr, img_data);
	}
    else
	{
        if (x_ys[1] > x_ys[3])
		{
			ft_swap(&x_ys[0], &x_ys[2]);
			ft_swap(&x_ys[1], &x_ys[3]);
            plotLineHigh(x_ys, addr, img_data);
		}
		else
			plotLineHigh(x_ys, addr, img_data);   
	}
}

void ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_atox(char *n)
{
	int	len;
	int	result;

	if (n == NULL)
		return (0x00ffffff);
	len = 0;
	result = 0;
	if (*n == '0')
	{
		n++;
		if (*n == 'x')
			n++;
	}
	else
		return (0);
	len = ft_strlen(n);
	while (*(n))
	{
		*n = ft_tolower(*n);
		if (ft_isdigit(*n))
			result += ((*n++) - '0') * (pow(16, --len));
		else
			result += ((*n++) - 'a' + 10) * (pow(16, --len));
	}
	return (result);
}

/*
Ref to Bersenham's algorith:
https://en.wikipedia.org/wiki/Bresenham
*/