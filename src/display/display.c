#include "libft.h"
#include "display.h"
#include "geometry.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

t_display	*del_display(t_display *disp)
{
	if (disp->img)
		mlx_destroy_image(disp->mlx, disp->img);
	if (disp->win)
		mlx_destroy_window(disp->mlx, disp->win);
	free(disp);
	return (NULL);
}

t_display	*create_display(int width, int height, char *title)
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
	disp->w = width;
	disp->h = height;
	disp->img = mlx_new_image(disp->mlx, width, height);
	if (!disp->img)
		return (del_display(disp));
	disp->img_addr = mlx_get_data_addr(disp->img, (int *)&disp->bpp, (int *)&disp->nbytes, (int *)&disp->endian);
	if (!disp->img_addr)
		return (del_display(disp));
	mlx_destroy_image(disp->mlx, disp->img);
	disp->img_addr = NULL;
	return (disp);
}

int	start_buffer_display(t_display *disp)
{
	int	a[3];

	disp->img = mlx_new_image(disp->mlx, disp->w, disp->h);
	if (!disp->img)
		return (-1);
	disp->img_addr = mlx_get_data_addr(disp->img, a, a + 1, a + 2);
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

void	refresh_frame(t_display *disp, t_map *map)
{
	int		i;
	t_pixel	s;
	t_pixel	e;

	start_buffer_display(disp);
	i = 0;
	while (i < map->n_e)
	{
		s.x = disp->v[map->e[i].s].x;
		s.y = disp->v[map->e[i].s].y;
		e.x = disp->v[map->e[i].e].x;
		e.y = disp->v[map->e[i].e].y;
		s.color = 0xFFFFFFFF;
		e.color = 0xFFFFFFFF;
		putline_display(disp, s, e);
		i++;
	}
	end_buffer_display(disp);
}
