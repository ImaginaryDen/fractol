#include "fractol.h"

void init_fractol(t_fractol *fractol)
{
	fractol->cnst_num.re = -1;
	fractol->cnst_num.im = 0;
	fractol->moveX = 0.;
	fractol->moveY = 0.;
	fractol->zoom = 1;
	fractol->max.re = 0;
	fractol->max.im = 0;
}