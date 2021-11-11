#include "fractol.h"

void init_fractol(t_fractol *fractol)
{
	fractol->cnst_num.re = -0.8;
	fractol->cnst_num.im = 0.156;
	fractol->moveX = 0.;
	fractol->moveY = 0.;
	fractol->zoom = 1;
}