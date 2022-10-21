#include "display.h"

static unsigned int	avg_color(unsigned int a, unsigned int b)
{
	unsigned int	out;
	int				i;
	unsigned int	col[3];

	out = 0;
	i = 0;
	while (i < 4)
	{
		col[0] = (unsigned char)(a >> (i * 8));
		col[1] = (unsigned char)(b >> (i * 8));
		col[2] = ((a + b) / 2) << (i * 8);
		out |= col[2];
		i++;
	}
	return (out);
}

static void	putpixel_display(t_display *disp, t_pixel p)
{
	int	o_height;
	int	o_width;

	if (p.x < 0 || p.x >= disp->w)
		return ;
	if (p.y < 0 || p.y >= disp->h)
		return ;
	o_height = disp->nbytes * p.y;
	o_width = p.x * disp->bpp / 8;
	*(int *)(disp->img_addr + o_height + o_width) = p.color;
}

static void	putline_display_recur(t_display *disp, t_pixel s, t_pixel e)
{
	t_pixel	m;
	int		dx;
	int		dy;

	dx = s.x - e.x;
	dy = s.y - e.y;
	if (-1 <= dx && dx <= 1 && -1 <= dy && dy <= 1)
		return ;
	m.x = (s.x + e.x) / 2;
	m.y = (s.y + e.y) / 2;
	m.color = avg_color(s.color, e.color);
	putpixel_display(disp, s);
	putpixel_display(disp, e);
	putpixel_display(disp, m);
	putline_display_recur(disp, s, m);
	putline_display_recur(disp, m, e);
}

int	putline_display(t_display *disp, t_pixel s, t_pixel e)
{
	if (!disp->img)
		return (-1);
	putpixel_display(disp, s);
	putpixel_display(disp, e);
	putline_display_recur(disp, s, e);
	return (0);
}
