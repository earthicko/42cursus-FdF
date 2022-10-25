#include "libft.h"
#include "mlx_interface.h"
#include "display.h"
#include "geometry.h"
#include "consts.h"
#include "parser.h"
#include "debug.h"
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

t_state	*create_state(char *map_path)
{
	t_state	*state;

	state = (t_state *)malloc(sizeof(t_state));
	if (!state)
		return (NULL);
	ft_memset(state, 0, sizeof(t_state));
	state->map = parse_map(map_path);
	if (!state->map)
		return (del_state(state));
	center_map(state->map);
	ft_printf("map lodaded\n");
	print_map(state->map);
	state->cam = create_camera(state->map);
	if (!state->cam)
		return (del_state(state));
	state->disp = create_display(SCREEN_W, SCREEN_H,
			(char *)SCREEN_TITLE);
	if (!state->disp)
		return (del_state(state));
	if (refresh_frame(state))
		return (del_state(state));
	return (state);
}

int	refresh_frame(t_state *state)
{
	if (project_to_camera(state->cam, state->map))
		return (-1);
	if (project_to_display(state->disp, state->cam))
		return (-1);
	putframe_display(state->disp, state->map);
	return (0);
}
