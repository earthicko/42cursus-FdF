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

#include "projection_bonus.h"
#include <stdlib.h>
#include <math.h>
#include <limits.h>

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
		disp->v = (t_pixel *)malloc(sizeof(t_pixel) * cam->n_v);
		if (!disp->v)
			return (-1);
		disp->n_v = cam->n_v;
	}
	i = 0;
	while (i < cam->n_v)
	{
		disp->v[i].x = map_screen_to_display(cam->v[i].x, disp->w);
		disp->v[i].y = map_screen_to_display(cam->v[i].y, disp->h);
		if (cam->v[i].z < 0)
			disp->v[i].color = 0x00FFFFFF;
		else
			disp->v[i].color = 0x00000000;
		i++;
	}
	return (0);
}
