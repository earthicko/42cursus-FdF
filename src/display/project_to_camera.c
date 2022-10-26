/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_to_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:11:00 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:11:03 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "consts.h"
#include "display.h"
#include <stdlib.h>
#include <limits.h>

static int	alloc_camera_v(t_camera *cam, int n_v)
{
	if (cam->v)
		free(cam->v);
	if (cam->is_visible)
		free(cam->is_visible);
	cam->v = malloc(sizeof(t_vertex) * n_v);
	if (!cam->v)
		return (-1);
	cam->is_visible = malloc(sizeof(int) * n_v);
	if (!cam->is_visible)
	{
		free(cam->v);
		cam->v = NULL;
		return (-1);
	}
	cam->n_v = n_v;
	return (0);
}

static int	is_visible(t_vertex *v)
{
	if (!(-CLIPPING_XY_D < v->x && v->x < CLIPPING_XY_D))
		return (0);
	if (!(-CLIPPING_XY_D < v->y && v->y < CLIPPING_XY_D))
		return (0);
	return (1);
}

static void	project_vertex_isometric(t_camera *cam, t_map *map, int i)
{
	multiply_vertex_m44(cam->v + i, map->v + i, &cam->wtoc);
	if (-cam->v[i].z > map->grid_size * RESOLUTION)
	{
		cam->v[i].x = cam->v[i].x / cam->isometric_d;
		cam->v[i].y = cam->v[i].y / cam->isometric_d;
		cam->is_visible[i] = is_visible(&cam->v[i]);
	}
}

static void	project_vertex_perspective(t_camera *cam, t_map *map, int i)
{
	multiply_vertex_m44(cam->v + i, map->v + i, &cam->wtoc);
	if (-cam->v[i].z > map->grid_size * RESOLUTION)
	{
		cam->v[i].x = -cam->v[i].x / cam->v[i].z;
		cam->v[i].y = -cam->v[i].y / cam->v[i].z;
		cam->is_visible[i] = is_visible(&cam->v[i]);
		if (cam->is_visible[i] && - cam->v[i].z < cam->min_z)
			cam->min_z = -cam->v[i].z;
	}
}

int	project_to_camera(t_camera *cam, t_map *map)
{
	int	i;

	if (cam->n_v != map->n_v && alloc_camera_v(cam, map->n_v))
		return (-1);
	cam->min_z = __DBL_MAX__;
	i = 0;
	while (i < map->n_v)
	{
		cam->is_visible[i] = 0;
		if (cam->mode == CAMMODE_ISOMETRIC)
			project_vertex_isometric(cam, map, i);
		else if (cam->mode == CAMMODE_PERSPECTIVE)
			project_vertex_perspective(cam, map, i);
		i++;
	}
	return (0);
}
