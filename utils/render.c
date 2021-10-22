#include "fractol.h"

int	render(t_vars *vars)
{
	julia_set(&vars->img);
	refresh_win(vars);
	vars->frame_counter++;
	ft_putstr_fd("end\n", 1);
	return (0);
}