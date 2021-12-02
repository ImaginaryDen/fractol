#include "fractol.h"
#include <stdio.h>
void get_show(t_vars *vars)
{
	double x;
	double y;
	const int pr = 100;

	while (1)
	{
		x = 10;
		while(x < pr)
		{
			y = 0;
			while(y < pr)
			{
				printf("re = %f im = %f\n",x/(pr / 2.),y/(pr / 2.));
				vars->fractol.cnst_num.re = x/(pr / 2);
				vars->fractol.cnst_num.im = y/(pr / 2);
				full_set(vars);
				refresh_win(vars);
				y++;
			}
			x++;
		}
	}
}