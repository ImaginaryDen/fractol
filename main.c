#include "fractol.h"
#include <stdio.h>

int	main(void)
{
	t_vars	vars;
	t_fractol fractol;

	init_mlx(&vars);
	mlx_loop(vars.mlx);
}
