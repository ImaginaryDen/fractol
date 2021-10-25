#include "fractol.h"

int init_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	//set_win_close(vars);
	vars->frame_counter = 0;
	vars->img.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length,
								&vars->img.endian);
	init_fractol(&vars->fractol);
	mlx_key_hook(vars->win, key_hook, vars);
	//mlx_loop_hook(vars->mlx, render, vars);
	julia_set(vars);
	refresh_win(vars);
	return (0);
}