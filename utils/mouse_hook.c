#include "fractol.h"
#include <stdio.h>

int mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == M_SCRL_UP)
	{
		vars->fractol.moveX -= (WIN_HEIGHT / 2. - x)/ vars->fractol.zoom;
		move_x(vars, (WIN_HEIGHT / 2. - x));
		vars->fractol.moveY -= (WIN_WIDTH / 2. - y)/ vars->fractol.zoom;
		move_y(vars, (WIN_WIDTH / 2. - y));
		vars->fractol.zoom *= 2;
		move_p(vars);
	}
	if (button == M_SCRL_DW)
	{
		vars->fractol.moveX -= (WIN_HEIGHT / 2. - x)/ vars->fractol.zoom;
		move_x(vars, (WIN_HEIGHT / 2. - x));
		vars->fractol.moveY -= (WIN_WIDTH / 2. - y)/ vars->fractol.zoom;
		move_y(vars, (WIN_WIDTH / 2. - y));
		vars->fractol.zoom /= 2;
		move_m(vars);
	}
	refresh_win(vars);
	return (0);
}