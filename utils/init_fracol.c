/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fracol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:27:44 by tjamis            #+#    #+#             */
/*   Updated: 2022/01/18 14:20:00 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(t_fractol *fractol)
{
	fractol->cnst_num.re = -0.8;
	fractol->cnst_num.im = 0.156;
	fractol->movex = 0.;
	fractol->movey = 0.;
	fractol->zoom = 1;
}
