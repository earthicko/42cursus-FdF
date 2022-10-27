/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_to_display_bonus.c                         :+:      :+:    :+:   */
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
#include <math.h>

static void	map_screen_to_display(t_display *disp, t_camera *cam, int i)
{
	t_uint	alpha;
	t_uchar	color[4];
	double	alpha_ratio;

	disp->v[i].x = (cam->v[i].x + 1.0) * disp->w / 2.0;
	disp->v[i].y = (cam->v[i].y + 1.0) * disp->ratio * disp->h / 2.0;
	if (cam->mode == CAMMODE_ISOMETRIC)
		alpha = UCHAR_MAX;
	else
	{
		alpha_ratio = pow(-cam->max_z / cam->v[i].z, 2);
		alpha = (t_uint)((double)UCHAR_MAX * alpha_ratio);
		if (alpha > UCHAR_MAX)
			alpha = UCHAR_MAX;
	}
	color[0] = 0xFF;
	color[1] = 0xFF;
	color[2] = 0xFF;
	color[3] = UCHAR_MAX - alpha;
	disp->v[i].color = *(t_uint *)color;
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
		if (cam->is_visible[i])
			map_screen_to_display(disp, cam, i);
		i++;
	}
	return (CODE_OK);
}
