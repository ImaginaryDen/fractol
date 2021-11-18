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
				pixel_put(new_img, x , y , *(unsigned int *)get_x_y(vars->img, x - shift, y));
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
				pixel_put(new_img, x , y , *(unsigned int *)get_x_y(vars->img, x, y - shift));
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

void image_zero(t_img_data *img)
{
	int	x;
	int	y;

	y = 0;
	while(y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_HEIGHT)
		{
			pixel_put(img, x, y, get_color(0,1));
			x++;
		}
		y++;
	}
}

void set_sq_color(int x, int y, t_img_data *img, unsigned int color)
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

void	move_p(t_vars *vars)
{
	int	x;
	int	y;
	unsigned int color;
	t_img_data *new_img;

	new_img = init_new_img(vars->mlx);
	image_zero(new_img);
	y = WIN_HEIGHT / 4;
	while(y < WIN_HEIGHT - WIN_HEIGHT / 4)
	{
		x = WIN_WIDTH / 4;
		while(x < WIN_WIDTH - WIN_WIDTH / 4)
		{
			pixel_put(new_img, x + (x - WIN_WIDTH / 2 ) , y + (y - WIN_HEIGHT / 2), *(unsigned int *)get_x_y(vars->img, x, y));
			if (x != WIN_WIDTH / 4
				&& y != WIN_HEIGHT / 4)
			{
				color = *(unsigned int *)get_x_y(vars->img, x, y);
				if (color == *(unsigned int *)get_x_y(vars->img, x - 1, y)
					&& color == *(unsigned int *)get_x_y(vars->img, x, y - 1)
						&& color == *(unsigned int *)get_x_y(vars->img, x - 1, y - 1))
					{
						set_sq_color(x - 2 + (x - WIN_WIDTH / 2), y - 2 + (y - WIN_HEIGHT / 2), new_img, color);
					}
			}
			x++;
		}
		y++;
	}

	y = 0;
	while(y < WIN_HEIGHT)
	{
		x = 0;
		while(x < WIN_WIDTH)
		{
			if (*(unsigned int *)get_x_y(new_img, x, y) == get_color(0, 1))
				pixel_put(new_img, x, y,  get_color(vars->get_point(x, y, vars), vars->max_iter));
			x++;
		}
		y++;
	}
	mlx_destroy_image(vars->mlx, vars->img->img);
	free(vars->img);
	vars->img = new_img;
}

void	move_m(t_vars *vars)
{
	int	x;
	int	y;
	unsigned int color;
	t_img_data *new_img;

	new_img = init_new_img(vars->mlx);
	image_zero(new_img);
	y = WIN_HEIGHT / 4;
	while(y < WIN_HEIGHT - WIN_HEIGHT / 4)
	{
		x = WIN_WIDTH / 4;
		while(x < WIN_WIDTH - WIN_WIDTH / 4)
		{
			pixel_put(new_img, x, y, *(unsigned int *)get_x_y(vars->img, x + (x - WIN_WIDTH / 2 ), y + (y - WIN_HEIGHT / 2)));
			x++;
		}
		y++;
	}
	y = 0;
	while(y < WIN_HEIGHT)
	{
		x = 0;
		while(x < WIN_WIDTH)
		{
			if (*(unsigned int *)get_x_y(new_img, x, y) == get_color(0, 1))
				pixel_put(new_img, x, y,  get_color(vars->get_point(x, y, vars), vars->max_iter));
			x++;
		}
		y++;
	}
	mlx_destroy_image(vars->mlx, vars->img->img);
	free(vars->img);
	vars->img = new_img;
}