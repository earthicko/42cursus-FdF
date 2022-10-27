/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_to_camera_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:11:00 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:11:03 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_def.h"
#include "consts_bonus.h"
#include "display_bonus.h"
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
		return (CODE_ERROR_MALLOC);
	cam->is_visible = malloc(sizeof(int) * n_v);
	if (!cam->is_visible)
	{
		free(cam->v);
		cam->v = NULL;
		return (CODE_ERROR_MALLOC);
	}
	cam->n_v = n_v;
	return (CODE_OK);
}

static int	is_visible(t_vertex *v)
{
	if (!(-CLIPPING_XY_D < v->x && v->x < CLIPPING_XY_D))
		return (FALSE);
	if (!(-CLIPPING_XY_D < v->y && v->y < CLIPPING_XY_D))
		return (FALSE);
	return (TRUE);
}

static void	project_vertex_isometric(t_camera *cam, t_map *map, int i)
{
	multiply_vertex_m44(cam->v + i, map->v + i, &cam->wtoc);
	if (-cam->v[i].z > map->grid_size * RESOLUTION)
	{
		cam->v[i].x = cam->v[i].x / cam->isometric_d;
		cam->v[i].y = cam->v[i].y / cam->isometric_d;
		cam->v[i].color = map->v[i].color;
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
		cam->v[i].color = map->v[i].color;
		cam->is_visible[i] = is_visible(&cam->v[i]);
	}
}

int	project_to_camera(t_camera *cam, t_map *map)
{
	int	i;

	if (cam->n_v != map->n_v && alloc_camera_v(cam, map->n_v))
		return (CODE_ERROR_MALLOC);
	cam->max_z = map->grid_size * 150;
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
	return (CODE_OK);
}
