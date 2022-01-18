/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:27:48 by tjamis            #+#    #+#             */
/*   Updated: 2022/01/18 14:58:49 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_set(t_vars *vars, int argc, char **argv)
{
	if (!ft_strncmp(argv[1], "julia", 7))
	{
		vars->get_point = julia_set;
		if (argc >= 4)
		{
			vars->fractol.cnst_num.re = ft_atoi(argv[2]) / 500.;
			vars->fractol.cnst_num.im = ft_atoi(argv[3]) / 500.;
		}
	}
	else if (!ft_strncmp(argv[1], "mandelbrot", 12))
		vars->get_point = mandelbrot_set;
	else if (!ft_strncmp(argv[1], "burn", 5))
		vars->get_point = burn_set;
	else
		return (1);
	return (0);
}

int	init_mlx(t_vars *vars, int argc, char **argv)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		return (1);
	vars->color = 1;
	vars->max_iter = MAX_ITER;
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	vars->img = init_new_img(vars->mlx);
	init_fractol(&vars->fractol);
	if (init_set(vars, argc, argv))
		return (1);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_hook(vars->win, 2, 1L << 0, key_hook, vars);
	mlx_hook(vars->win, 17, 0, close_win, vars);
	full_set(vars);
	refresh_win(vars);
	return (0);
}
