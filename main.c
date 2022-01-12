#include "fractol.h"
#include <stdio.h>

void menu()
{
	ft_putendl_fd("Bad input", 1);
	ft_putendl_fd("Usage: ./fractol [name fractal] ", 1);
	ft_putendl_fd("Fractals supported:", 1);
	ft_putendl_fd(" --- mandelbrot", 1);
	ft_putendl_fd(" --- julia and params", 1);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if(argc < 2)
	{
		menu();
		return (1);
	}
	if (init_mlx(&vars, argc, argv))
	{
		menu();
		mlx_destroy_image(vars.mlx, vars.img->img);
		mlx_destroy_window(vars.mlx, vars.win);
		free(vars.img);
	}
	else
		mlx_loop(vars.mlx);
}
