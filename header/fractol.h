/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:01:06 by tjamis            #+#    #+#             */
/*   Updated: 2021/10/18 20:47:09 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <mlx.h>

# define WIN_WIDTH	1920
# define WIN_HEIGHT 1080
# define US_INT unsigned short int

int	create_trgb(US_INT t, US_INT r, US_INT g, US_INT b);

#endif
