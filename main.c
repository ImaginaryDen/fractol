#include "fractol.h"
#include <stdio.h>

int	key_hook(int keycode, t_vars *vars)
{
	t_img_data	img;

	img.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	for (int w = 0; w < WIN_WIDTH; w++)
		for (int h = 0; h < WIN_HEIGHT; h++)
		{
				pixel_put(&img, w, h, create_trgb(0, h * 255 / WIN_HEIGHT, w * 255  / WIN_WIDTH, keycode * 10));	
		}
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	set_win_close(&vars);
	mlx_loop(vars.mlx);
}
