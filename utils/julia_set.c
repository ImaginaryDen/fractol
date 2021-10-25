#include "fractol.h"

int get_color(int i)
{
	int r;
	int g;
	int b;

	if (i >= MAX_ITER)
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
			fractol->newn.re = 1.5 * (x - WIN_WIDTH / 2) / (0.5 * fractol->zoom * WIN_WIDTH) + fractol->moveX;
			fractol->newn.im = (y - WIN_HEIGHT / 2) / (0.5 * fractol->zoom * WIN_HEIGHT) + fractol->moveY;
			i = 0;
			while (i < MAX_ITER)
			{
				fractol->oldn = fractol->newn;
				fractol->newn.re = fractol->oldn.re * fractol->oldn.re - fractol->oldn.im * fractol->oldn.im + fractol->cnst_num.re;
				fractol->newn.im = 2 * fractol->oldn.re * fractol->oldn.im + fractol->cnst_num.im;
				if((fractol->newn.re * fractol->newn.re + fractol->newn.im * fractol->newn.im) > 4)
					break;
				i++;
			}
			pixel_put(&vars->img, x, y, get_color(i));
			x++;
		}
		y++;
	}
}
