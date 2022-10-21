#include "geometry.h"
#include "display.h"
#include "projection.h"
#include <stdio.h>
#include <stdlib.h>

int	project_to_camera(t_camera *cam, t_map *map)
{
	int	i;

	if (cam->n_v != map->n_v)
	{
		if (cam->v)
			free(cam->v);
		cam->v = (t_vertex *)malloc(sizeof(t_vertex) * map->n_v);
		if (!cam->v)
			return (-1);
		cam->n_v = map->n_v;
	}
	i = 0;
	while (i < map->n_v)
	{
		multiply_vertex_m44(cam->v + i, map->v + i, &cam->wtoc);
		cam->v[i].x = -cam->v[i].x / cam->v[i].z;
		cam->v[i].y = -cam->v[i].y / cam->v[i].z;
		i++;
	}
	return (0);
}

int	project_to_display(t_display *disp, t_camera *cam)
{
	int		i;
	double	x;
	double	y;

	if (disp->n_v != cam->n_v)
	{
		if (disp->v)
			free(disp->v);
		disp->v = (t_pixel *)malloc(sizeof(t_pixel) * cam->n_v);
		if (!disp->v)
			return (-1);
		disp->n_v = cam->n_v;
	}
	i = 0;
	while (i < cam->n_v)
	{
		x = (cam->v[i].x + 1.0) * disp->w / 2.0;
		y = (cam->v[i].y + 1.0) * disp->h / 2.0;
		disp->v[i].x = x;
		disp->v[i].y = y;
		i++;
	}
	return (0);
}
