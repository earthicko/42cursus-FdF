/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:37 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:38 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "projection.h"
#include <stdio.h>
#include <math.h>

void	print_camera(t_camera *cam)
{
	printf("azimuth %f deg, elevation %f deg\n",
		cam->azi * 180.0 / M_PI, cam->ele * 180.0 / M_PI);
	printf("World -> Cam\n");
	print_matrix(&cam->wtoc);
}
