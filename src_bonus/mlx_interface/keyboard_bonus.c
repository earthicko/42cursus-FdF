/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:50 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:51 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_interface_bonus.h"
#include <stdlib.h>

static void	increment_angle(int keycode, t_camera *cam)
{
	if (keycode == KEYCODE_I)
		increment_e_camera(cam, 1);
	else if (keycode == KEYCODE_K)
		increment_e_camera(cam, -1);
	else if (keycode == KEYCODE_J)
		increment_a_camera(cam, -1);
	else if (keycode == KEYCODE_L)
		increment_a_camera(cam, 1);
}

static void	increment_pos(int keycode, t_camera *cam)
{
	if (keycode == KEYCODE_Q)
		increment_xyz_camera(cam, 2, -1);
	else if (keycode == KEYCODE_E)
		increment_xyz_camera(cam, 2, 1);
	else if (keycode == KEYCODE_W)
		increment_xyz_camera(cam, 0, 1);
	else if (keycode == KEYCODE_S)
		increment_xyz_camera(cam, 0, -1);
	else if (keycode == KEYCODE_A)
		increment_xyz_camera(cam, 1, 1);
	else if (keycode == KEYCODE_D)
		increment_xyz_camera(cam, 1, -1);
}

int	mlx_key_interface(int k, void *param)
{
	t_state	*state;

	state = param;
	if (k == KEYCODE_Q || k == KEYCODE_E || k == KEYCODE_W)
		increment_pos(k, state->cam);
	else if (k == KEYCODE_S || k == KEYCODE_A || k == KEYCODE_D)
		increment_pos(k, state->cam);
	else if (k == KEYCODE_I || k == KEYCODE_J)
		increment_angle(k, state->cam);
	else if (k == KEYCODE_K || k == KEYCODE_L)
		increment_angle(k, state->cam);
	else if (k == KEYCODE_SP)
		switch_projection_mode(state->cam);
	if (refresh_frame(param))
	{
		del_state(state);
		exit(2);
	}
	return (0);
}
