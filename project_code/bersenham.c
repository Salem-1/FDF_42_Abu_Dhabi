#include "fdf.h"

//you can do all the declartion later in one line as static int vars[6];
void plotLineLow(int *x_ys, void *addr, int *img_data)
 {	// x0, y0, x1, y1, color)
	int dx;
	int dy;
	int yi;
	int D;
	int	y;
	int x;

	dx = x_ys[2] - x_ys[0];
    dy = x_ys[3] - x_ys[1];
    yi = 1;
    if (dy < 0)
    {   
		yi = -1;
        dy = -dy;
    }
    D = (2 * dy) - dx;
    y = x_ys[1];
	x = x_ys[0] - 1;
	while (++x < x_ys[2])
	{	//ft_printf(" x0 = %d, x1 = %d", x, x_ys[2]);

		x_ys[0] = x;
		x_ys[1] = y;
        my_mlx_pixel_put(addr, x_ys, img_data);
        if (D > 0)
		{
            y = y + yi;
            D = D + (2 * (dy - dx));
		}
		else
            D = D + 2 * dy;
	}
 }

void plotLineHigh(int *x_ys, void *addr, int *img_data)
 {	// x0, y0, x1, y1, color)
	int dx;
	int dy;
	int xi;
	int D;
	int	y;
	int x;

	dx = x_ys[2] - x_ys[0];
    dy = x_ys[3] - x_ys[1];
    xi = 1;
    if (dx < 0)
    {   xi = -1;
        dx = -dx;
    }
    D = (2 * dx) - dy;
    x = x_ys[0];
	y = x_ys[1] - 1;
	while (++y < x_ys[3])
	{
		//ft_printf(" y0 = %d, y1 = %d\n", y, x_ys[3]);
		x_ys[0] = x;
		x_ys[1] = y;
        my_mlx_pixel_put(addr, x_ys, img_data);
        if (D > 0)
		{
            x = x + xi;
            D = D + (2 * (dx - dy));
		}
		else
            D = D + 2 * dx;

	}
 }
void connect_dots(int *x_ys, void *addr, int *img_data)
{
	int	tmp;
	//ft_printf("last pixel on the plnet (%d, %d) to (%d, %d)\n", img_data[0],
	//	 img_data[1], img_data[2], img_data[3]);
    if (abs(x_ys[3] - x_ys[1]) < abs(x_ys[2] - x_ys[0]))
    {   
		if (x_ys[0] > x_ys[2])
		{
			tmp = x_ys[0];
			x_ys[0] = x_ys[2];
			x_ys[2] = tmp;
			tmp = x_ys[1];
			x_ys[1] = x_ys[3];
			x_ys[3] = tmp;
			
            plotLineLow(x_ys, addr, img_data);
		}
		else
            plotLineLow(x_ys, addr, img_data);
		
	}
    else
	{
        if (x_ys[1] > x_ys[3])
		{
			tmp = x_ys[0];
			x_ys[0] = x_ys[2];
			x_ys[2] = tmp;
			tmp = x_ys[1];
			x_ys[1] = x_ys[3];
			x_ys[3] = tmp;
            plotLineHigh(x_ys, addr, img_data);
		}
		else
		{
            
			plotLineHigh(x_ys, addr, img_data);   
				
		}
	}
}

/*
Ref to Bersenham's algorith:
https://en.wikipedia.org/wiki/Bresenham
*/