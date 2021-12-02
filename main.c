#include "fractol.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_vars	vars;

	if(argc < 2)
	{
		printf("Error\n");
		return (1);
	}
	if (init_mlx(&vars, argc, argv))
	{
		printf("Error\n");
		mlx_destroy_image(vars.mlx, vars.img->img);
		mlx_destroy_window(vars.mlx, vars.win);
		free(vars.img);
	}
	else
	{
		//get_show(&vars);
		mlx_loop(vars.mlx);
	}
}
