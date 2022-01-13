#include"fractol.h"

void	move_p(t_vars *vars)
{
	int	x;
	int	y;
	t_img_data *new_img;

	new_img = init_new_img(vars->mlx);
	image_zero(new_img);
	y = WIN_HEIGHT / 4;
	while(y < WIN_HEIGHT - WIN_HEIGHT / 4)
	{
		x = WIN_WIDTH / 4;
		while(x < WIN_WIDTH - WIN_WIDTH / 4)
		{
			fill_sq(vars, new_img, x, y);
			x++;
		}
		y++;
	}
	fill_space(vars, new_img);
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
	fill_space(vars, new_img);
	mlx_destroy_image(vars->mlx, vars->img->img);
	free(vars->img);
	vars->img = new_img;
}