#include "fractol.h"


int HSVtoRGB(float H, float S,float V)
{
	float s = S/100;
	float v = V/100;
	float C = s*v;
	float X = C*(1-fabs(fmod(H/60.0, 2)-1));
	float m = v-C;
	float r,g,b;
	if(H >= 0 && H < 60){
		r = C,g = X,b = 0;
	}
	else if(H >= 60 && H < 120){
		r = X,g = C,b = 0;
	}
	else if(H >= 120 && H < 180){
		r = 0,g = C,b = X;
	}
	else if(H >= 180 && H < 240){
		r = 0,g = X,b = C;
	}
	else if(H >= 240 && H < 300){
		r = X,g = 0,b = C;
	}
	else{
		r = C,g = 0,b = X;
	}
	int R = (r+m)*255;
	int G = (g+m)*255;
	int B = (b+m)*255;
	return (create_trgb(0, R, G, B));
}

void	julia_set(t_img_data *img)
{
	t_im_nbr const_nbr;
	t_im_nbr oldn;
	t_im_nbr newn;
	double	zoom = 1;
	double	moveX = 0;
	double	moveY = 0;
	int	i;
	int maxIterations = 300;
	int x;
	int	y;

	const_nbr.real = -0.7;
	const_nbr.im = 0.25015;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			newn.real = 1.5 * (x - WIN_WIDTH / 2) / (0.5 * zoom * WIN_WIDTH) + moveX;
			newn.im = (y - WIN_HEIGHT / 2) / (0.5 * zoom * WIN_HEIGHT) + moveY;
			i = 0;
			while (i < maxIterations)
			{
				oldn.im = newn.im;
				oldn.real = newn.real;
				newn.real = oldn.real * oldn.real - oldn.im * oldn.im + const_nbr.real;
				newn.im = 2 * oldn.real * oldn.im + const_nbr.im;
				if((newn.real * newn.real + newn.im * newn.im) > 4)
					break;
				i++;
			}
			pixel_put(img, x, y, HSVtoRGB(i % 256, 255, 255 * (i < maxIterations)));
			x++;
		}
		y++;
	}
}
