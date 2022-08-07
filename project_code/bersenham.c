#include "fdf.h"


void connect_dots(int *x_ys, void *addr, int *img_data)
	//int x0,int y0,int x1,int y1)
{
	static int d[4] = {0};
	int			error;
	int			e2;

    d[0] = abs(x_ys[2] - x_ys[0]); //dx
	if (x_ys[0] < x_ys[2])
		d[1] = 1;//sx
	else
		d[1] = -1;
    d[2] = -abs(x_ys[2] - x_ys[1]); //dy
    if (x_ys[1] < x_ys[2])
		d[3] = 1; //sy
	else
		d[3] = -1;
	error = d[0] + d[2];
    while(1)
	{
		my_mlx_pixel_put(addr, x_ys, img_data);
		//put_pixel(x0, y0);
		if (x_ys[0] == x_ys[2] && x_ys[1] == x_ys[2]) 
			break;
		e2 = 2 * error;
		if (e2 >= d[2])
		{
			if (x_ys[0] == x_ys[2])
				break;
			error = error + d[2];
			x_ys[0] = x_ys[0] + d[1];
		}
		if (e2 <= d[0])
		{
			if (x_ys[1] == x_ys[2])
				break;
			error = error + d[0];
			x_ys[1] = x_ys[1] + d[3];
		}
    }
}
/*
x_ys[0] = ; //x0
x_ys[1] = ; //y0
x_ys[2] = ; //x1
x_ys[2] = ; //y1
x_ys[4] = ; //color
*/

/*
Ref to Bersenham's algorith:
https://en.wikipedia.org/wiki/Bresenham
*/