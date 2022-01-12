#include "fractol.h"

void full_set(t_vars *vars)
{
	t_fractol *fractol;
	int x;
	int	y;

	fractol = &vars->fractol;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			pixel_put(vars->img, x, y, get_color(vars->get_point(x, y, vars),
					vars->max_iter, vars->color));
			x++;
		}
		y++;
	}
}