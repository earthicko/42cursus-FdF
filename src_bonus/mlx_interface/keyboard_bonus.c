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

int	mlx_key_interface(int keycode, void *param)
{
	t_state	*state;

	state = param;
	if (keycode == KEYCODE_W)
		increment_e_camera(state->cam, 1);
	else if (keycode == KEYCODE_A)
		increment_a_camera(state->cam, -1);
	else if (keycode == KEYCODE_S)
		increment_e_camera(state->cam, -1);
	else if (keycode == KEYCODE_D)
		increment_a_camera(state->cam, 1);
	else if (keycode == KEYCODE_Q)
		increment_r_camera(state->cam, -1);
	else if (keycode == KEYCODE_E)
		increment_r_camera(state->cam, 1);
	if (refresh_frame(param))
	{
		del_state(state);
		exit(2);
	}
	return (0);
}
