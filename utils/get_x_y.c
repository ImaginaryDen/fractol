#include "fractol.h"

void	*get_x_y(t_img_data *img, int x, int y)
{
	char	*dst;
	
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return dst;
}
