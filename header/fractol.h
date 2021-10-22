/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:01:06 by tjamis            #+#    #+#             */
/*   Updated: 2021/10/22 18:27:10 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"

# define WIN_WIDTH	1920
# define WIN_HEIGHT 1080
# define US_INT unsigned short int

typedef struct	s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;

typedef struct	s_vars {
	void			*mlx;
	void			*win;
	t_img_data		img;
	unsigned int	frame_counter;
}				t_vars;

typedef struct	s_im_nbr{
	double real;
	double im;
}				t_im_nbr;

int		create_trgb(US_INT t, US_INT r, US_INT g, US_INT b);
void	pixel_put(t_img_data *data, int x, int y, int color);
void	set_win_close(t_vars *vars);
int		render(t_vars *vars);
int		init_mlx(t_vars *vars);
void	*get_x_y(t_vars *vars, int x, int y);
void	julia_set(t_img_data *img);
void	refresh_win(t_vars *vars);

#endif
