/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_increment_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:59 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:11:00 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "consts_bonus.h"
#include "display_bonus.h"
#include <math.h>

void	increment_e_camera(t_camera *cam, int dir)
{
	cam->ele += cam->step_a * dir;
	refresh_camera(cam);
}

void	increment_a_camera(t_camera *cam, int dir)
{
	cam->azi += cam->step_a * dir;
	refresh_camera(cam);
}

void	increment_xyz_camera(t_camera *cam, int axis, int dir)
{
	if (axis == AXIS_X)
	{
		cam->orig.x += dir * cam->step_d * cos(cam->ele) * sin(cam->azi);
		cam->orig.y += -dir * cam->step_d * cos(cam->ele) * cos(cam->azi);
	}
	else if (axis == AXIS_Y)
	{
		cam->orig.x += -dir * cam->step_d * cos(cam->ele) * cos(cam->azi);
		cam->orig.y += -dir * cam->step_d * cos(cam->ele) * sin(cam->azi);
	}
	else if (axis == AXIS_Z)
		cam->orig.z += dir * cam->step_d * sin(cam->ele) / 2;
	refresh_camera(cam);
}

void	increment_isometric_d_camera(t_camera *cam, int dir)
{
	if (dir > 0)
		cam->isometric_d /= INCREMENT_SCALE;
	else if (dir < 0)
		cam->isometric_d *= INCREMENT_SCALE;
}
