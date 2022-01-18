/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:11:49 by tjamis            #+#    #+#             */
/*   Updated: 2022/01/18 16:22:08 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	menu(void)
{
	ft_putendl_fd("Bad input", 1);
	ft_putendl_fd("Usage: ./fractol [name fractal] ", 1);
	ft_putendl_fd("Fractals supported:", 1);
	ft_putendl_fd(" --- mandelbrot", 1);
	ft_putendl_fd(" --- julia and two params [-1000 ~ 1000]", 1);
	ft_putendl_fd(" --- burn", 1);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc < 2)
	{
		menu();
		return (1);
	}
	if (init_mlx(&vars, argc, argv))
	{
		menu();
		close_win(&vars);
	}
	else
		mlx_loop(vars.mlx);
}
