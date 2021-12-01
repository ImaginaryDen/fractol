/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:01:06 by tjamis            #+#    #+#             */
/*   Updated: 2021/12/01 16:24:55 by tjamis           ###   ########.fr       */
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

# define WIN_WIDTH	1000.L
# define WIN_HEIGHT 1000.L

# define US_INT unsigned short int
# define MAX_ITER 400
# define MIN_ITER 300

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
}				t_fractol;

typedef struct	s_vars {
	void			*mlx;
	void			*win;
	t_img_data		*img;
	t_fractol		fractol;
	int				max_iter;
	int				(*get_point) (int x, int y,
						struct s_vars *vars);
}				t_vars;

int			create_trgb(US_INT t, US_INT r, US_INT g, US_INT b);
void		pixel_put(t_img_data *data, int x, int y, int color);
void		set_win_close(t_vars *vars);
int			render(t_vars *vars);
int			init_mlx(t_vars *vars, int argc, char **argv);
void		refresh_win(t_vars *vars);
void		init_fractol(t_fractol *fractol);
int			key_hook(int key, t_vars *vars);
t_img_data	*init_new_img(void *mlx);
void		*get_x_y(t_img_data *img, int x, int y);
void		move_y(t_vars *vars, const double shift);
void		move_x(t_vars *vars, const double shift);
int			get_color(int i, int max_iter);
int			julia_set(int x, int y, t_vars *vars);
int			mandelbrot_set(int x, int y, t_vars *vars);
void		full_set(t_vars *vars);
void		move_p(t_vars *vars);
void		move_m(t_vars *vars);
int			mouse_hook(int button, int x, int y, t_vars *vars);

#endif
