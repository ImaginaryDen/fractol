/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:13:20 by tjamis            #+#    #+#             */
/*   Updated: 2022/01/18 14:59:27 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	full_set(t_vars *vars)
{
	int			x;
	int			y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			pixel_put(vars->img, x, y, get_color(vars->get_point(x, y, vars),
					vars->max_iter, vars->color));
			x++;
		}
		y++;
	}
}
