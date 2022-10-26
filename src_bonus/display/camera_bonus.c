/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:58 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:59 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "consts_bonus.h"
#include "display_bonus.h"
#include <math.h>

void	refresh_camera(t_camera *cam)
{
	ft_printf("Camera at (%d, %d, %d), a=%d deg, e=%d deg\n",
		(int)-cam->orig.x,
		(int)-cam->orig.y,
		(int)-cam->orig.z,
		(int)(cam->azi * 180.0 / M_PI),
		(int)(cam->ele * 180.0 / M_PI));
	init_matrix44_identity(&cam->wtoc);
	translate_m44_inplace(&cam->wtoc, &cam->orig);
	rotate_m44_inplace(&cam->wtoc, 2, -cam->azi);
	rotate_m44_inplace(&cam->wtoc, 0, -(M_PI_2 - cam->ele));
}

static void	initialize_cam(t_camera *cam, t_map *map)
{
	double	width;
	double	height;
	double	radius;

	width = (map->x_bound[1] - map->x_bound[0]) / 2;
	height = (map->y_bound[1] - map->y_bound[0]) / 2;
	radius = sqrt(width * width + height * height) * 2;
	cam->azi = M_PI * 5 / 4;
	cam->ele = M_PI * 3 / 4;
	cam->step_d = radius / STEP_PER_DISTANCE;
	cam->step_a = M_PI / STEP_PER_ROTATION;
	cam->orig.x = radius * cos(M_PI - cam->ele) * cos(cam->azi);
	cam->orig.y = radius * cos(cam->ele) * sin(cam->azi);
	cam->orig.z = -radius * sin(cam->ele);
}

t_camera	*create_camera(t_map *map)
{
	t_camera	*cam;

	cam = (t_camera *)malloc(sizeof(t_camera));
	if (!cam)
		return (NULL);
	ft_memset(cam, 0, sizeof(t_camera));
	initialize_cam(cam, map);
	ft_printf("Camera Initial Settings\n");
	ft_printf("Step of angle: %d, Step of distance: %d\n",
		(int)(cam->step_a * 180 / M_PI),
		(int)(cam->step_d));
	refresh_camera(cam);
	return (cam);
}

void	del_camera(t_camera *cam)
{
	if (cam->v)
		free(cam->v);
	free(cam);
}
