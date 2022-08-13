#include "fdf.h"

void mlx_operations(int ***map)
{
	void *mlx;
	void *mlx_window;
	t_vars vars;

	//t_data	img;
	static int 	img_data[3] = {0}; //[bits/pixel, line_length, edian]
	void *img;
	void *addr;
	
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 1900, 1080, "Hello World");
	img = mlx_new_image(mlx, 1900, 1080);
	vars.mlx = mlx;
	vars.win = mlx_window;						
	addr = mlx_get_data_addr(img, &img_data[0], &img_data[1], &img_data[2]);
	fill_map_horizontal(map, addr, (int *)img_data);
	//fill_map_vertical(map, addr, (int *)img_data);
	clean_map(map);
	mlx_put_image_to_window(mlx, mlx_window, img, 0, 0);
	mlx_hook(vars.win, 2, 1L << 0 , close_with_esc, &vars);
	mlx_hook(vars.win, 17, 1L << 0 , close_with_x, &vars);
	// mlx_loop_hook(mlx, close_me, &vars);
	 mlx_loop(mlx);
}
int close_with_esc (int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		//ft_printf("window destroyed using esc");
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
		return (0);
	}
	return (0);
}

int close_with_x(t_vars *vars)
{
		// mlx_destroy_window(vars->mlx, vars->win);
		(void)vars;
		exit(1);
		return (0);
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

	//Forcing rotating the map, which is quick and dirty way , that is not scalable, replace this with matrix rotation
	//  x  = (x - y) / sqrt(2);
	// y  = (x + y) / sqrt(2);
	//ft_printf("        inside pixel pu\n");
	if (x > 0  && y > 0 && x <= 1900 && y <= 1080)
	{
		dst = addr + (y * img_data[1]  + x * (img_data[0] / 8));
	//	ft_printf("%x\n",x_ys[4] );
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
	int	move_image = 500;

	i = -1;
	j = -1;
	k = -1;
	while (map[++i])
	{
		while (map[i][++j ] && map[i ]) //break before last pixel
		{
			//horizintal lines
			if (map[i][j + 1])
			{
				x_ys[0] = map[i][j][0] + move_image ; //x0
				x_ys[1] = map[i][j][1] + move_image; //y0
				x_ys[2] = map[i][j + 1][0] + move_image ; //x1
				x_ys[3] = map[i][j + 1][1]  + move_image; //y1
				if (map[i][j + 1][3] > map[i][j][3])
					x_ys[4] = map[i][j + 1][3]; //color
		        else
					x_ys[4] = map[i][j][3];
			//	ft_printf("color = %x\n", x_ys[4]);
			//	ft_printf("last survivor point map[%d][%d][%d]------", i, j, 0);
                connect_dots(x_ys, addr, img_data);
			    
            }//vertical lines
			if (map[i + 1])
			{
				x_ys[0] = map[i][j][0] + move_image; //x0
				x_ys[1] = map[i][j][1] + move_image; //y0
				x_ys[2] = map[i + 1][j][0] + move_image; //x1
				x_ys[3] = map[i + 1][j][1] + move_image; //y1
				if(map[i + 1][j][3] > map[i][j][3])
					x_ys[4] = map[i + 1][j][3]; //color
				else
					x_ys[4] = map[i][j][3];
				//ft_printf("color = %x\n", x_ys[4]);
            //    ft_printf("last survivor point map[%d][%d][%d]\n", i, j, 0);
				connect_dots(x_ys, addr, img_data);
			}
		}
		j = -1;
	}	
}
