#include "fdf.h"


void mlx_operations(int ***map)
{
	void *mlx;
	void *mlx_window;
	//t_data	img;
	static int 	img_data[3] = {0}; //[bits/pixel, line_length, edian]
	void *img;
	void *addr;
	
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 1920, 1080, "Hello World");
	img = mlx_new_image(mlx, 1920, 1080);
									
	addr = mlx_get_data_addr(img, &img_data[0], &img_data[1], &img_data[2]);
	fill_map_horizontal(map, addr, (int *)img_data);
	mlx_put_image_to_window(mlx, mlx_window, img, 0, 0);
	mlx_loop(mlx);
}

//refractor this to put_pixel
//x_ys (x0, y0, x1, y1, color)
void my_mlx_pixel_put(void *addr, int *x_ys, int *img_data)
{
	char *dst;

	dst = addr + (x_ys[1] * img_data[1] + x_ys[0] * (img_data[0] /8));
	*(unsigned int*)dst = x_ys[4];
	//ft_printf("Putting pixel %x \n", dst);
}

void fill_map_horizontal(int ***map, void *addr, int *img_data)
{
	//I need x1, y1, x2, y2, color
	int	i;
	int	j;
	int	k;
	static int x_ys[5] = {0};

	i = -1;
	j = -1;
	k = -1;
	while (map[++i])
	{
		while (map[i][++j + 1]) //break before last pixel
		{
			x_ys[0] = map[i][j][0]; //x1
			x_ys[1] = map[i][j][1]; //y1
			x_ys[2] = map[i][j + 1][0]; //x2
			x_ys[3] = map[i][j + 1][1]; //y2
			x_ys[4] = map[i][j][3]; //color
			connect_dots(x_ys, addr, img_data);
		}
		j = -1;
	}	
}
