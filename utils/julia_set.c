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

void	julia_set(t_vars *vars)
{
	t_fractol *fractol;
	int	i;
	int x;
	int	y;

	fractol = &vars->fractol;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			fractol->newn.re = 4 * (x - WIN_HEIGHT * 0.5L) / (WIN_HEIGHT * fractol->zoom) + fractol->moveX;
			fractol->newn.im = 4 * (y - WIN_WIDTH * 0.5L) / (WIN_WIDTH * fractol->zoom) + fractol->moveY;
			i = 0;
			while (i < vars->max_iter)
			{
				fractol->oldn = fractol->newn;
				fractol->newn.re = fractol->oldn.re * fractol->oldn.re - fractol->oldn.im * fractol->oldn.im + fractol->cnst_num.re;
				fractol->newn.im = 2 * fractol->oldn.re * fractol->oldn.im + fractol->cnst_num.im;
				if((fractol->newn.re * fractol->newn.re + fractol->newn.im * fractol->newn.im) > 4)
					break;
				i++;
			}
			pixel_put(&vars->img, x, y, get_color(i, vars->max_iter));
			x++;
		}
		y++;
	}
}
