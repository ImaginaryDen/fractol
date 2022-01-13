#include "fractol.h"

void	image_zero(t_img_data *img)
{
	int	x;
	int	y;

	y = 0;
	while(y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_HEIGHT)
		{
			pixel_put(img, x, y, get_color(0,1,1));
			x++;
		}
		y++;
	}
}

void	set_sq_color(int x, int y, t_img_data *img, unsigned int color)
{
	int x_i;
	int y_i;

	y_i = y;
	y++;
	while(*(unsigned int *)get_x_y(img, x, y) != color)
		y++;
	y++;
	while(y_i < y)
	{
		x_i = x;
		while (x_i - x < y - y_i)
		{
			pixel_put(img, x_i, y_i, color);
			x_i++;
		}
		y_i++;
	}
}

void	fill_space(t_vars *vars, t_img_data *new_img)
{
	int	x;
	int	y;

	y = 0;
	while(y < WIN_HEIGHT)
	{
		x = 0;
		while(x < WIN_WIDTH)
		{
			if (*(unsigned int *)get_x_y(new_img, x, y) ==
				get_color(0, 1, vars->color))
				pixel_put(new_img, x, y,  get_color(vars->get_point(x, y, vars),
					vars->max_iter, vars->color));
			x++;
		}
		y++;
	}
}

void	fill_sq(t_vars *vars, t_img_data *new_img, int x, int y)
{
	unsigned int color;

	pixel_put(new_img, x + (x - WIN_WIDTH / 2 ),
				y + (y - WIN_HEIGHT / 2),
					*(unsigned int *)get_x_y(vars->img, x, y));
			if (x != WIN_WIDTH / 4
				&& y != WIN_HEIGHT / 4)
			{
				color = *(unsigned int *)get_x_y(vars->img, x, y);
				if (color == *(unsigned int *)get_x_y(vars->img, x - 1, y)
					&& color == *(unsigned int *)get_x_y(vars->img, x, y - 1)
						&& color ==
							*(unsigned int *)get_x_y(vars->img, x - 1, y - 1))
					{
						set_sq_color(x - 2 + (x - WIN_WIDTH / 2),
							y - 2 + (y - WIN_HEIGHT / 2), new_img, color);
					}
			}
}
