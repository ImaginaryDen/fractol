#include "fractol.h"
#include <stdio.h>

int key_hook(int key, t_vars *vars)
{
	const double shift = WIN_HEIGHT / (20. * vars->fractol.zoom);

	if (key == KEY_A)
	{
		vars->fractol.moveX -= shift ;
		move_x(vars, shift * vars->fractol.zoom);
	}
	if (key == KEY_D)
	{
		vars->fractol.moveX += shift;
		move_x(vars, -shift * vars->fractol.zoom);
	}
	if (key == KEY_W)
	{
		vars->fractol.moveY -= shift;
		move_y(vars, shift * vars->fractol.zoom);
	}
	if (key == KEY_S)
	{
		vars->fractol.moveY += shift;
		move_y(vars, -shift * vars->fractol.zoom);
	}
	if (key == KEY_PLUS)
	{
		vars->fractol.zoom *= 2;
		move_p(vars);
		//full_set(vars);
	}
	if (key == KEY_MINUS)
	{
		vars->fractol.zoom /= 2;
		move_m(vars);
		//full_set(vars);
	}
	if (key == KEY_Q)
		vars->max_iter-= 10;
	if (key == KEY_E)
		vars->max_iter+= 10;
	if (key == KEY_ESC)
	{
		mlx_destroy_image(vars->mlx, vars->img->img);
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->img);
		exit(0);
	}
	if (key == KEY_SPACE)
	{
		ft_putnbr_fd(vars->max_iter, 1);
		ft_putstr_fd("\n", 1);
		full_set(vars);
	}
	refresh_win(vars);
	return (0);
}