#include "fractol.h"

double abs_d(double num)
{
	if (num < 0)
		return -num;
	return num;
}

int	burn_set(int x, int y, t_vars *vars)
{
	long double temp;
	t_complex	complex;
	t_complex	const_complex;
	int			i;
	const int	max_iter = vars->max_iter;

	complex.re = 4 * (x + vars->fractol.moveX * vars->fractol.zoom - WIN_HEIGHT * 0.5L) / (WIN_HEIGHT * vars->fractol.zoom);
	complex.im = 4 * (y + vars->fractol.moveY * vars->fractol.zoom - WIN_WIDTH * 0.5L) / (WIN_WIDTH * vars->fractol.zoom);
	const_complex = complex;
	i = 0;
	while (i < max_iter)
	{
		temp = complex.re * complex.re - complex.im * complex.im + const_complex.re;
		complex.im =  abs_d(2 * complex.re * complex.im) + const_complex.im;
		complex.re = temp;
		if((complex.re * complex.re + complex.im * complex.im) > 4)
			break;
		i++;
	}
	return (i);
}