/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:01:06 by tjamis            #+#    #+#             */
/*   Updated: 2021/10/27 20:04:45 by tjamis           ###   ########.fr       */
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
# include "key.h"

# define WIN_WIDTH	500.L
# define WIN_HEIGHT 500.L

# define US_INT unsigned short int
# define MAX_ITER 200
# define MIN_ITER 100

typedef struct	s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;

typedef struct	s_complex{
	double re;
	double im;
}				t_complex;

typedef struct	s_fractol
{
	t_complex		cnst_num;
	t_complex		newn;
	t_complex		oldn;
	long double		zoom;
	long double		moveX;
	long double		moveY;
	t_complex		max;
}				t_fractol;

typedef struct	s_vars {
	void			*mlx;
	void			*win;
	t_img_data		*img;
	unsigned int	frame_counter;
	t_fractol		fractol;
	int				max_iter;
}				t_vars;

int			create_trgb(US_INT t, US_INT r, US_INT g, US_INT b);
void		pixel_put(t_img_data *data, int x, int y, int color);
void		set_win_close(t_vars *vars);
int			render(t_vars *vars);
int			init_mlx(t_vars *vars);
void		julia_set(t_vars *vars);
void		refresh_win(t_vars *vars);
void		init_fractol(t_fractol *fractol);
int			key_hook(int key, t_vars *vars);
t_img_data	*init_new_img(void *mlx);
void		*get_x_y(t_vars *vars, int x, int y);
void		move_x(t_vars *vars, const double shift);
void		move_y(t_vars *vars, const double shift);
int			get_color(int i, int max_iter);
int			check_pointr(int x, int y, t_vars *vars, const long double re_c, const long double im_c);

#endif
