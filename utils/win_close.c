#include "fractol.h"
#include <stdio.h>

int	win_close(int keycode, t_vars *vars)
{
	if (keycode == 53 || keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_image(vars->mlx, vars->img->img);
		exit(0);
	}
	return (0);
}

void set_win_close(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L<<0, win_close, vars);
}