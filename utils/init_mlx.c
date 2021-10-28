#include "fractol.h"

int init_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	vars->frame_counter = 0;
	vars->img = init_new_img(vars->mlx);
	init_fractol(&vars->fractol);
	mlx_key_hook(vars->win, key_hook, vars);
	vars->max_iter = MIN_ITER;
	julia_set(vars);
	refresh_win(vars);
	return (0);
}