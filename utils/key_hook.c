#include "fractol.h"

#include <stdio.h>

int key_hook(int key, t_vars *vars)
{
	if (key == KEY_A)
		vars->fractol.moveX -= 0.1 / vars->fractol.zoom;
	else if (key == KEY_D)
		vars->fractol.moveX += 0.1 / vars->fractol.zoom;
	else if (key == KEY_W)
		vars->fractol.moveY -= 0.1 / vars->fractol.zoom;
	else if (key == KEY_S)
		vars->fractol.moveY += 0.1 / vars->fractol.zoom;
	else if (key == KEY_PLUS)
	{
		if(vars->max_iter < MAX_ITER)
			vars->max_iter += 5;
		vars->fractol.zoom *= 2;
	}
	else if (key == KEY_MINUS)
	{
		if  (vars->max_iter > MIN_ITER)
			vars->max_iter -= 5;
		vars->fractol.zoom /= 2;
	}
	if (key == KEY_Q)
		vars->max_iter-= 10;
	if (key == KEY_E)
		vars->max_iter+= 10;
	else if (key == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_image(vars->mlx, vars->img.img);
		exit(0);
	}
	ft_putnbr_fd(vars->max_iter, 1);
	ft_putstr_fd("\n", 1);	
	julia_set(vars);
	refresh_win(vars);
	return (0);
}