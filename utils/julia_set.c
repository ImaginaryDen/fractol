#include "fractol.h"

int get_color(int i, int max_iter)
{
	int r;
	int g;
	int b;

	if (i >= max_iter)
	{
		r = 141;
		g = 26;
		b = 187;
	}
	else
	{
		r = (i * 12) % 255;
		g = (i * 0) % 255;
		b = (i * 6) % 255;
	}
	return (create_trgb(20, r, g, b));
}

int	check_pointr(int x, int y, t_vars *vars, const long double re_c, const long double im_c)
{
	long double temp;
	long double re;
	long double im;
	int			i;
	const int	max_iter = vars->max_iter;

	re = 4 * (x - WIN_HEIGHT * 0.5L) / (WIN_HEIGHT * vars->fractol.zoom) + vars->fractol.moveX;
	im = 4 * (y - WIN_WIDTH * 0.5L) / (WIN_WIDTH * vars->fractol.zoom) + vars->fractol.moveY;
	i = 0;
	while (i < max_iter)
	{
		temp = re * re - im * im + re_c;
		im = 2 * re * im + im_c;
		re = temp;
		if((re * re + im * im) > 4)
			break;
		i++;
	}
	return (i);
}

void	julia_set(t_vars *vars)
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
			pixel_put(vars->img, x, y, get_color(check_pointr(x, y, vars, vars->fractol.cnst_num.re, vars->fractol.cnst_num.im), vars->max_iter));
			x++;
		}
		y++;
	}
}
