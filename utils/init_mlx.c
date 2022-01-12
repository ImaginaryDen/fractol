#include "fractol.h"

int init_mlx(t_vars *vars, int argc, char **argv)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		return(0);
	vars->color = 1;
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	vars->img = init_new_img(vars->mlx);
	init_fractol(&vars->fractol);
	if (!ft_strncmp(argv[1], "julia", 6))
	{
		vars->get_point = julia_set;
		if (argc >= 4)
		{
			vars->fractol.cnst_num.re = ft_atoi(argv[2])/500.;
			vars->fractol.cnst_num.im = ft_atoi(argv[3])/500.;
		}
	}
	else if (!ft_strncmp(argv[1], "mandelbrot", 11))
		vars->get_point = mandelbrot_set;
	else if (!ft_strncmp(argv[1], "burn", 4))
		vars->get_point = burn_set;
	else
		return (1);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_hook(vars->win, 17, 0, close_win, vars);
	vars->max_iter = MAX_ITER;
	full_set(vars);
	refresh_win(vars);
	return (0);
}