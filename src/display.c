#include "libft.h"
#include "display.h"
#include "mlx.h"
#include <stdlib.h>

t_display	*del_display(t_display *disp)
{
	free(disp);
	return (NULL);
}

t_display	*create_display(int width, int height, const char *title)
{
	t_display	*disp;

	disp = malloc(sizeof(t_display));
	if (!disp)
		return (NULL);
	ft_memset(disp, 0, sizeof(t_display));
	disp->mlx = mlx_init();
	if (!disp->mlx)
		return (del_display(disp));
	disp->win = mlx_new_window(disp->mlx, width, height, title);
	if (!disp->win)
		return (del_display(disp));
	disp->width = width;
	disp->height = height;
	disp->img_addr = mlx_get_data_addr(disp->img, &disp->bpp, &disp->nbytes, &disp->endian);
	if (!disp->img_addr)
		return (del_display(disp));
	mlx_destroy_image(disp->mlx, disp->img);
	disp->img_addr = NULL;
	return (disp);
}

int	start_buffer_display(t_display *disp)
{
	disp->img = mlx_new_image(disp->mlx, disp->width, disp->height);
	if (!disp->img)
		return (-1);
	disp->img_addr = mlx_get_data_addr(disp->img, NULL, NULL, NULL);
	return (0);
}

static void	putpixel_display(t_display *disp, t_pixel p)
{
	if (p.x < 0 || p.x > disp->width)
		return ;
	if (p.y < 0 || p.y > disp->height)
		return ;
	*(int *)(disp->img_addr + disp->nbytes * p.y + p.x * disp->bpp / 8) = p.color;
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

int	end_buffer_display(t_display *disp)
{
	if (!disp->img)
		return (-1);
	mlx_put_image_to_window(disp->mlx, disp->win, disp->img, 0, 0);
	mlx_destroy_image(disp->mlx, disp->img);
	disp->img = NULL;
	return (0);
}
