#include "projection.h"
#include "mlx_interface.h"
#include "debug.h"
#include <stdio.h>

int	mlx_key_interface(int keycode, void *param)
{
	t_state	*state;

	state = param;
	// w: 119, a: 97, s: 115, d: 100
	// q: 113, e: 101
	printf("key hook: keycode %d, param: %p\n", keycode, param);
	if (keycode == 119)
		increment_e_camera(state->cam, 1);
	else if (keycode == 97)
		increment_a_camera(state->cam, -1);
	else if (keycode == 115)
		increment_e_camera(state->cam, -1);
	else if (keycode == 100)
		increment_a_camera(state->cam, 1);
	refresh_frame(param);
	return (0);
}
