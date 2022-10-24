#include "projection.h"
#include "mlx_interface.h"
#include "debug.h"
#include <stdio.h>
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
	if (refresh_frame(param))
	{
		del_state(state);
		exit(2);
	}
	return (0);
}
