/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:29:33 by tjamis            #+#    #+#             */
/*   Updated: 2022/01/18 14:37:33 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	key_move(int key, t_vars *vars)
{
	const double	shift = WIN_HEIGHT / (20. * vars->fractol.zoom);

	if (key == KEY_A)
	{
		vars->fractol.movex -= shift;
		move_x(vars, shift * vars->fractol.zoom);
	}
	if (key == KEY_D)
	{
		vars->fractol.movex += shift;
		move_x(vars, -shift * vars->fractol.zoom);
	}
	if (key == KEY_W)
	{
		vars->fractol.movey -= shift;
		move_y(vars, shift * vars->fractol.zoom);
	}
	if (key == KEY_S)
	{
		vars->fractol.movey += shift;
		move_y(vars, -shift * vars->fractol.zoom);
	}
}

void	key_zoom(int key, t_vars *vars)
{
	if (key == KEY_PLUS)
	{
		vars->fractol.zoom *= 2;
		move_p(vars);
	}
	if (key == KEY_MINUS)
	{
		vars->fractol.zoom /= 2;
		move_m(vars);
	}
}

void	key_iter(int key, t_vars *vars)
{
	if (key == KEY_Q)
		vars->max_iter -= 10;
	if (key == KEY_E)
		vars->max_iter += 10;
}

int	key_hook(int key, t_vars *vars)
{
	key_move(key, vars);
	key_zoom(key, vars);
	key_iter(key, vars);
	if (key == KEY_ESC)
		close_win(vars);
	if (key == KEY_SPACE)
		full_set(vars);
	if (key == KEY_C)
	{
		if (vars->color == 1)
			vars->color = 2;
		else
			vars->color = 1;
		full_set(vars);
	}
	refresh_win(vars);
	return (0);
}
