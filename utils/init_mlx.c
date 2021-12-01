#include "fractol.h"

int init_mlx(t_vars *vars, int argc, char **argv)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	vars->img = init_new_img(vars->mlx);
	init_fractol(&vars->fractol);
	if (!ft_strncmp(argv[1], "julia", 6))
		vars->get_point = julia_set;
	else if (!ft_strncmp(argv[1], "mandelbrot", 6))
		vars->get_point = mandelbrot_set;
	else
		return (1);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	vars->max_iter = MIN_ITER;
	full_set(vars);
	refresh_win(vars);
	return (0);
}