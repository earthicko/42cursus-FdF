/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:58 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:59 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "display.h"
#include <math.h>

void	refresh_camera(t_camera *cam)
{
	t_vertex	temp;

	temp.x = 0;
	temp.y = 0;
	temp.z = -cam->radius;
	init_matrix44_identity(&cam->wtoc);
	rotate_m44_inplace(&cam->wtoc, 2, -cam->azi);
	rotate_m44_inplace(&cam->wtoc, 0, -(M_PI_2 - cam->ele));
	translate_m44_inplace(&cam->wtoc, &temp);
}

static double	get_initial_cam_radius(t_map *map)
{
	double	width;
	double	height;

	width = (map->x_bound[1] - map->x_bound[0]) / 2;
	height = (map->y_bound[1] - map->y_bound[0]) / 2;
	return (sqrt(width * width + height * height) * 2);
}

t_camera	*create_camera(t_map *map)
{
	t_camera	*cam;

	cam = (t_camera *)malloc(sizeof(t_camera));
	if (!cam)
		return (NULL);
	ft_memset(cam, 0, sizeof(t_camera));
	cam->azi = -M_PI / 4;
	cam->ele = M_PI - M_PI / 4;
	cam->radius = get_initial_cam_radius(map);
	ft_printf("Camera Initial Settings\n");
	ft_printf("Azimuth: %d, Elevation: %d, Radius: %d\n",
		(int)(cam->azi * 180 / M_PI),
		(int)(cam->ele * 180 / M_PI),
		(int)(cam->radius * 180 / M_PI));
	refresh_camera(cam);
	return (cam);
}

void	del_camera(t_camera *cam)
{
	if (cam->v)
		free(cam->v);
	free(cam);
}