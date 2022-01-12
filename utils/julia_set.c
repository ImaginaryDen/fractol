#include "fractol.h"

int get_color(int i, int max_iter, int color)
{
	int r;
	int g;
	int b;

	if (i >= max_iter)
	{
		if (color == 1)
		{
			r = 141;
			g = 26;
			b = 187;
		}else
		{
			r = 0;
			g = 155;
			b = 75;
		}
	}
	else
	{
		if (color == 1)
		{
			r = (i * 12) % 255;
			g = (i * 0) % 255;
			b = (i * 6) % 255;
		}else
		{
			r = (i * 0) % 255;
			g = (i * 12) % 255;
			b = (i * 8) % 255;
		}
	}
	return (create_trgb(20, r, g, b));
}

int	julia_set(int x, int y, t_vars *vars)
{
	long double temp;
	t_complex	complex;
	t_complex	const_complex;
	int			i;
	const int	max_iter = vars->max_iter;

	complex.re = 4 * (x + vars->fractol.moveX * vars->fractol.zoom - WIN_HEIGHT * 0.5L) / (WIN_HEIGHT * vars->fractol.zoom);
	complex.im = 4 * (y + vars->fractol.moveY * vars->fractol.zoom - WIN_WIDTH * 0.5L) / (WIN_WIDTH * vars->fractol.zoom);
	const_complex = vars->fractol.cnst_num;
	i = 0;
	while (i < max_iter)
	{
		temp = complex.re * complex.re - complex.im * complex.im + const_complex.re;
		complex.im = 2 * complex.re * complex.im + const_complex.im;
		complex.re = temp;
		if((complex.re * complex.re + complex.im * complex.im) > 4)
			break;
		i++;
	}
	return (i);
}

