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
#include <stdlib.h>

void	refresh_camera(t_camera *cam)
{
	ft_printf("camera: at (%d, %d, %d), a=%d deg, e=%d deg, iso=%d\n",
		(int)-cam->orig.x,
		(int)-cam->orig.y,
		(int)-cam->orig.z,
		(int)(cam->azi * 180.0 / M_PI),
		(int)(cam->ele * 180.0 / M_PI),
		(int)cam->isometric_d);
	init_matrix44_identity(&cam->wtoc);
	translate_m44_inplace(&cam->wtoc, &cam->orig);
	rotate_m44_inplace(&cam->wtoc, AXIS_Z, -cam->azi);
	rotate_m44_inplace(&cam->wtoc, AXIS_X, -(M_PI_2 - cam->ele));
}

static void	initialize_cam(t_camera *cam, t_map *map)
{
	double	width;
	double	height;
	double	radius;

	width = (map->x_bound[1] - map->x_bound[0]) / 2;
	height = (map->y_bound[1] - map->y_bound[0]) / 2;
	radius = sqrt(pow(width, 2) + pow(height, 2)) * 2;
	cam->azi = CAM_AZIMUTH_DEFAULT;
	cam->ele = M_PI - CAM_ELEVATION_DEFAULT;
	cam->step_d = radius / STEP_PER_DISTANCE;
	cam->step_a = M_PI / STEP_PER_ROTATION;
	cam->orig.x = -radius * cos(cam->ele) * cos(cam->azi);
	cam->orig.y = radius * cos(cam->ele) * sin(cam->azi);
	cam->orig.z = -radius * sin(cam->ele);
	cam->max_z = RESOLUTION;
	cam->isometric_d = map->span * ((double)SCREEN_W / SCREEN_H) / 2;
}

t_camera	*create_camera(t_map *map)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	if (!cam)
		return (NULL);
	ft_bzero(cam, sizeof(t_camera));
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
	if (cam->is_visible)
		free(cam->is_visible);
	free(cam);
}

void	switch_projection_mode(t_camera *cam)
{
	cam->mode++;
	if (cam->mode > CAMMODE_MAX)
		cam->mode = 0;
	ft_printf("camera: projection mode switched to %d\n", cam->mode);
}
