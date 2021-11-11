#include "fractol.h"

void	move_x(t_vars *vars, const double shift)
{
	int	x;
	int	y;
	t_img_data *new_img;

	new_img = init_new_img(vars->mlx);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (x - shift < WIN_WIDTH && x - shift > 0)
				pixel_put(new_img, x , y , *(unsigned int *)get_x_y(vars, x - shift, y));
			else
				pixel_put(new_img, x, y , get_color(vars->get_point(x, y, vars),
						vars->max_iter));
			x++;
		}
		y++;
		
	}
	mlx_destroy_image(vars->mlx, vars->img->img);
	free(vars->img);
	vars->img = new_img;
}

void	move_y(t_vars *vars, const double shift)
{
	int	x;
	int	y;
	t_img_data *new_img;

	new_img = init_new_img(vars->mlx);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y - shift < WIN_WIDTH && y - shift > 0)
				pixel_put(new_img, x , y , *(unsigned int *)get_x_y(vars, x, y - shift));
			else
				pixel_put(new_img, x, y , get_color(vars->get_point(x, y, vars),
						vars->max_iter));
			x++;
		}
		y++;
		
	}
	mlx_destroy_image(vars->mlx, vars->img->img);
	free(vars->img);
	vars->img = new_img;
}