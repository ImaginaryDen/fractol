#include "fractol.h"

void	*get_x_y(t_vars *vars, int x, int y)
{
	char	*dst;
	
	dst = vars->img->addr + (y * vars->img->line_length + x * (vars->img->bits_per_pixel / 8));
	return dst;
}
