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
	mlx_window = mlx_new_window(mlx, 1900, 1080, "Hello World");
	img = mlx_new_image(mlx, 1900, 1080);
									
	addr = mlx_get_data_addr(img, &img_data[0], &img_data[1], &img_data[2]);
	fill_map_horizontal(map, addr, (int *)img_data);
	//fill_map_vertical(map, addr, (int *)img_data);
	mlx_put_image_to_window(mlx, mlx_window, img, 0, 0);
	mlx_loop(mlx);
}

//refractor this to put_pixel
//x_ys (x0, y0, x1, y1, color)
void my_mlx_pixel_put(void *addr, int *x_ys, int *img_data)
{
	char *dst;
	int		x;
	int		y;

	x = x_ys[0] ;
	y = x_ys[1];

	//x  = (x - y) / sqrt(2);
	//y  = (x + y) / sqrt(2);
	//ft_printf("        inside pixel pu\n");
	if (x_ys[0] > 0  && x_ys[1] > 0 && x_ys[0] <= 1900 && x_ys[1] <= 1080)
	{
		dst = addr + (y * img_data[1]  + x * (img_data[0] /8));
		*(unsigned int*)dst = x_ys[4];
	}
	//ft_printf("Putting pixel %x \n", dst);
}

void fill_map_horizontal(int ***map, void *addr, int *img_data)
{
	//I need x1, y1, x2, y2, color
	int	i;
	int	j;
	int	k;
	static int x_ys[5] = {0};
	int scale_constant = 2;
	int	move_image = 2;

	i = -1;
	j = -1;
	k = -1;
	while (map[++i])
	{
		while (map[i][++j + 1] && map[i + 1]) //break before last pixel
		{
			x_ys[0] = map[i][j][0] * scale_constant + move_image; //x0
			x_ys[1] = map[i][j][1] * scale_constant + move_image; //y0
			x_ys[2] = map[i][j + 1][0] * scale_constant + move_image; //x1
			x_ys[3] = map[i][j + 1][1] * scale_constant + move_image; //y1
			x_ys[4] = map[i][j][3]; //color
			connect_dots(x_ys, addr, img_data);
			x_ys[0] = map[i][j][0] * scale_constant + move_image; //x0
			x_ys[1] = map[i][j][1] * scale_constant + move_image; //y0
			x_ys[2] = map[i + 1][j][0] * scale_constant + move_image; //x1
			x_ys[3] = map[i + 1][j][1] * scale_constant + move_image; //y1
			x_ys[4] = map[i][j][3]; //color
			connect_dots(x_ys, addr, img_data);
		}
		j = -1;
	}	
}
/*
void	fill_map_vertical(int ***map, void *addr, int *img_data)
{
	//I need x1, y1, x2, y2, color
	int	i;
	int	j;
	int	k;
	static int x_ys[5] = {0};
	int scale_constant = 50;
	int	move_image = 200;

	i = 0;
	j = -1;
	k = -1;
	while (map[i][++j])
	{
		while (map[i + 1]) //break before last pixel
		{
			x_ys[0] = map[i][j][0] * scale_constant + move_image; //x0
			x_ys[1] = map[i][j][1] * scale_constant + move_image; //y0
			x_ys[2] = map[i + 1][j][0] * scale_constant + move_image; //x1
			x_ys[3] = map[i + 1][j][1] * scale_constant + move_image; //y1
			x_ys[4] = map[i][j][3]; //color
			connect_dots(x_ys, addr, img_data);
			i++;
		}
		i = 0;
		
	}	
}*/