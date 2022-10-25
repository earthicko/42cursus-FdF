/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_increment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:59 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:11:00 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "projection.h"
#include <math.h>

void	increment_e_camera(t_camera *cam, int dir)
{
	cam->ele += cam->step_a * dir;
	ft_printf("Camera elevation set to %d\n", (int)(cam->ele * 180.0 / M_PI));
	refresh_camera(cam);
}

void	increment_a_camera(t_camera *cam, int dir)
{
	cam->azi += cam->step_a * dir;
	ft_printf("Camera Azimuth set to %d\n", (int)(cam->azi * 180.0 / M_PI));
	refresh_camera(cam);
}

void	increment_r_camera(t_camera *cam, int dir)
{
	cam->radius += cam->step_d * dir;
	ft_printf("Camera Radius set to %d\n", (int)(cam->radius * 180.0 / M_PI));
	refresh_camera(cam);
}
