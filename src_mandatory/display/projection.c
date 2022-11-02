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

#include "libft.h"
#include "display.h"
#include <stdlib.h>

int	project_to_camera(t_camera *cam, t_map *map)
{
	int	i;

	if (cam->n_v != map->n_v)
	{
		if (cam->v)
			free(cam->v);
		cam->v = malloc(sizeof(t_vertex) * map->n_v);
		if (!cam->v)
			return (CODE_ERROR_MALLOC);
		cam->n_v = map->n_v;
	}
	i = 0;
	while (i < map->n_v)
	{
		multiply_vertex_m44(cam->v + i, map->v + i, &cam->wtoc);
		cam->v[i].x = cam->v[i].x / cam->isometric_d;
		cam->v[i].y = cam->v[i].y / cam->isometric_d;
		cam->v[i].color = map->v[i].color;
		i++;
	}
	return (CODE_OK);
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
			return (CODE_ERROR_MALLOC);
		disp->n_v = cam->n_v;
	}
	i = 0;
	while (i < cam->n_v)
	{
		disp->v[i].x = (cam->v[i].x + 1.0) * disp->w / 2.0;
		disp->v[i].y = (cam->v[i].y * disp->ratio + 1.0) * disp->h / 2.0;
		disp->v[i].color = cam->v[i].color;
		i++;
	}
	return (CODE_OK);
}
