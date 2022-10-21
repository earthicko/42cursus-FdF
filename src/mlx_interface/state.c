#include "libft.h"
#include "mlx_interface.h"
#include "display.h"
#include "geometry.h"
#include "consts.h"
#include "test.h"
#include <stdlib.h>

t_state	*del_state(t_state *state)
{
	if (state->map)
		del_map(state->map);
	if (state->cam)
		del_camera(state->cam);
	if (state->disp)
		del_display(state->disp);
	free(state);
	return (NULL);
}

t_state	*create_state(void)
{
	t_state	*state;

	state = (t_state *)malloc(sizeof(t_state));
	if (!state)
		return (NULL);
	ft_memset(state, 0, sizeof(t_state));
	state->map = make_cube();
	if (!state->map)
		return (del_state(state));
	state->cam = create_camera();
	if (!state->cam)
		return (del_state(state));
	state->disp = create_display(SCREEN_W, SCREEN_H,
			(char *)SCREEN_TITLE);
	if (!state->disp)
		return (del_state(state));
	refresh_frame(state);
	return (state);
}

void	refresh_frame(t_state *state)
{
	project_to_camera(state->cam, state->map);
	project_to_display(state->disp, state->cam);
	putframe_display(state->disp, state->map);
}
