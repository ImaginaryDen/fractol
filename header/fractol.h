/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:01:06 by tjamis            #+#    #+#             */
/*   Updated: 2021/10/21 19:50:49 by tjamis           ###   ########.fr       */
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

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;

int		create_trgb(US_INT t, US_INT r, US_INT g, US_INT b);
void	pixel_put(t_img_data *data, int x, int y, int color);
void	set_win_close(t_vars *vars);

#endif
