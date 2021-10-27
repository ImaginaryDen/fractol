#include "fractol.h"

void init_fractol(t_fractol *fractol)
{
	fractol->cnst_num.re = -0.7;
	fractol->cnst_num.im = 0.27015;
	fractol->moveX = 0.;
	fractol->moveY = 0.;
	fractol->zoom = 1;
	fractol->max.re = 0;
	fractol->max.im = 0;
}