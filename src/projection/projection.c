#include "geometry.h"
#include "display.h"
#include "projection.h"
#include <stdio.h>
#include <stdlib.h>

void	project_to_camera(t_map *map, t_camera *cam)
{
	int	i;

	i = 0;
	while (i < map->n_vertices)
	{
		multiply_vertex_matrix44(map->v_p + i, map->v + i, &cam->wtoc);
		map->v_p[i].x = -map->v_p[i].x / map->v_p[i].z;
		map->v_p[i].y = -map->v_p[i].y / map->v_p[i].z;
		i++;
	}
}

void	project_to_screen(t_display *disp, t_map *map)
{
	int		i;
	double	x;
	double	y;

	if (disp->v)
		free(disp->v);
	disp->v = malloc(sizeof(t_pixel) * map->n_vertices);
	disp->n_v = map->n_vertices;
	i = 0;
	while (i < map->n_vertices)
	{
		x = (map->v_p[i].x + 1.0) * disp->w / 2.0;
		y = (map->v_p[i].y + 1.0) * disp->h / 2.0;
		disp->v[i].x = x;
		disp->v[i].y = y;
		i++;
	}
}
