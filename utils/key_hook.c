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
		vars->fractol.zoom *= 2;
	else if (key == KEY_MINUS)
		vars->fractol.zoom /= 2;
	if (key == KEY_Q)
		vars->iter-= 2;
	if (key == KEY_E)
		vars->iter+= 2;
	else if (key == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_image(vars->mlx, vars->img.img);
		exit(0);
	}
	vars->max_iter = (MAX_ITER * vars->iter);
	ft_putnbr_fd(vars->max_iter, 1);
	ft_putstr_fd("\n", 1);	
	julia_set(vars);
	refresh_win(vars);
	return (0);
}