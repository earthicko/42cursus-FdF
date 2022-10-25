/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:11:00 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:11:03 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "consts_bonus.h"
#include "display_bonus.h"
#include <stdlib.h>
#include <math.h>
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

int	project_to_camera(t_camera *cam, t_map *map)
{
	int	i;

	if (cam->n_v != map->n_v && alloc_camera_v(cam, map->n_v))
		return (-1);
	i = 0;
	while (i < map->n_v)
	{
		multiply_vertex_m44(cam->v + i, map->v + i, &cam->wtoc);
		cam->is_visible[i] = 0;
		if (-cam->v[i].z > CLIPPING_Z_D)
		{
			cam->v[i].x = -cam->v[i].x / cam->v[i].z;
			cam->v[i].y = -cam->v[i].y / cam->v[i].z;
			cam->is_visible[i] = is_visible(&cam->v[i]);
		}
		i++;
	}
	return (0);
}

static int	map_screen_to_display(double src, double disp_size)
{
	if (src == INFINITY)
		return (INT_MAX);
	if (src == -INFINITY)
		return (INT_MIN);
	return ((src + 1.0) * disp_size / 2.0);
}

int	project_to_display(t_display *disp, t_camera *cam)
{
	int		i;

	if (disp->n_v != cam->n_v)
	{
		if (disp->v)
			free(disp->v);
		disp->v = malloc(sizeof(t_pixel) * cam->n_v);
		if (!disp->v)
			return (-1);
		disp->n_v = cam->n_v;
	}
	i = 0;
	while (i < cam->n_v)
	{
		if (cam->is_visible[i])
		{
			disp->v[i].x = map_screen_to_display(cam->v[i].x, disp->w);
			disp->v[i].y = map_screen_to_display(cam->v[i].y, disp->h);
			disp->v[i].color = 0x00FFFFFF;
		}
		i++;
	}
	return (0);
}
