#include "mlx.h"
#include "display.h"
#include "geometry.h"
#include "test.h"
#include "projection.h"
#include "debug.h"
#include "consts.h"
#include "mlx_interface.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	t_state	*state;

	state = create_state();
	if (!state)
		return (2);
	mlx_key_hook(state->disp->win, mlx_key_interface, state);
	mlx_loop(state->disp->mlx);
	return (0);
}
