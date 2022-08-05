#include "mlx/mlx.h"
#include <stdio.h>
#include <time.h>
//search for isometric projection wikipedia	

typedef struct s_data 
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		edian;
}	t_data;

//event variable data struct
typedef struct s_vars 
{
	void *mlx;
	void *win;
}	t_vars;

//the close event defination 
int close (int keycode, t_vars *vars)
{
	time_t s;
	
	if (keycode == 6)
		printf("Hello\n");
	else
		printf("Bye\n");

	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	if(keycode == 25)
		printf("window resized\n");
	s = time(NULL);
	while (keycode == 12)
	{
		if ((time(NULL) - s) > 2)
	{
		printf("The heart beats of the man telling him that life is only punch of minutes and seconds\n");
		break;
		}
			}
	return (0);
}
int key_hook(int keycode, t_vars *vars)
{
	printf("Hi from key hook, key_code = %d\n", keycode);
	return (0);
}

int mouse_hook(int keycode,int x, int y,  t_vars *vars)
{
	printf("(%d, %d)\n", x, y);
	return (0);
}


void my_mlx_pixel_put(t_data *data, int x, int y, int color);

int	main(void)
{
	void *mlx;
	void *mlx_window;
	t_data	img;
	int	i;
	t_vars vars;
	mlx = mlx_init();
	//doing the event handling operation
	vars.mlx = mlx;
	//opening new window
	mlx_window = mlx_new_window(mlx, 1920, 1080, "Hello World");

	//event handling part
	vars.win = mlx_window;
	//preparing an image and putting pixels on it
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.edian);
	for (i = 0; i < 100; i++)
	{
		my_mlx_pixel_put(&img, 200 + i, 100 + i + 1, 0x00FF0000 >> 16);
		my_mlx_pixel_put(&img, 200 - i, 100 + i + 1, 0x00FFFFFF);	
	}
	for (int j = 0; j < 200; j++)
		my_mlx_pixel_put(&img, 200 - i + j, 100 + i + 1, 0x00F000FF);
	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	//mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	//mlx_mouse_get_pos(vars.win, 200, 1000);
	//mlx_hook(vars.win, 2, 1L << 0, close, &vars);
	mlx_loop(mlx);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel /8));
	*(unsigned int*)dst = color;
}

