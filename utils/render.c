#include "fractol.h"

int	render(t_vars *vars)
{
	full_set(vars);
	refresh_win(vars);
	ft_putstr_fd("end\n", 1);
	return (0);
}