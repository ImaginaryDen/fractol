#include "fractol.h"

void refresh_win(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0,0);
}