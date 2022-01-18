/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:30:31 by tjamis            #+#    #+#             */
/*   Updated: 2022/01/18 14:20:05 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == M_SCRL_UP)
	{
		vars->fractol.zoom *= 2;
		move_p(vars);
		vars->fractol.movex -= (WIN_HEIGHT / 2. - x) / vars->fractol.zoom;
		move_x(vars, (WIN_HEIGHT / 2. - x));
		vars->fractol.movey -= (WIN_WIDTH / 2. - y) / vars->fractol.zoom;
		move_y(vars, (WIN_WIDTH / 2. - y));
	}
	if (button == M_SCRL_DW)
	{
		vars->fractol.movex -= (WIN_HEIGHT / 2. - x) / vars->fractol.zoom;
		move_x(vars, (WIN_HEIGHT / 2. - x));
		vars->fractol.movey -= (WIN_WIDTH / 2. - y) / vars->fractol.zoom;
		move_y(vars, (WIN_WIDTH / 2. - y));
		vars->fractol.zoom /= 2;
		move_m(vars);
	}
	refresh_win(vars);
	return (0);
}
