/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:32:24 by tjamis            #+#    #+#             */
/*   Updated: 2022/01/18 14:40:12 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	refresh_win(t_vars *vars)
{
	char	*str;

	str = ft_itoa(vars->max_iter);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	mlx_string_put(vars->mlx, vars->win, 1, 10,
		create_trgb(0, 225, 225, 225), str);
	free(str);
}
