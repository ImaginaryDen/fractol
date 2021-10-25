#include "fractol.h"

#include <stdio.h>

int key_hook(int key, t_vars *vars)
{
	if (key == 97)
		vars->fractol.moveX -= 0.1;
	else if (key == 100)
		vars->fractol.moveX += 0.1;
	else if (key == 115)
		vars->fractol.moveY += 0.1;
	else if (key == 119)
		vars->fractol.moveY -= 0.1;
	else if (key == 65451)
		vars->fractol.zoom += 0.1;
	else if (key == 65453)
		vars->fractol.zoom -= 0.1;
	else if (key == 53 || key== 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_image(vars->mlx, vars->img.img);
		exit(0);
	}
	julia_set(vars);
	refresh_win(vars);
}