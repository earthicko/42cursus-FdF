/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_interface.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:52 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:53 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "consts.h"
#include "parser.h"
#include "mlx_interface.h"
#include <stdlib.h>

int	exit_program(void *param)
{
	del_state((t_state *)param);
	exit(0);
}

int	mlx_key_interface(int k, void *param)
{
	if (k == KEYCODE_ESC)
		exit_program(param);
	return (0);
}

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

	state = malloc(sizeof(t_state));
	if (!state)
		return (NULL);
	ft_bzero(state, sizeof(t_state));
	state->map = parse_map(map_path);
	if (!state->map)
		return (del_state(state));
	center_map(state->map);
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
	int	ret;

	ret = project_to_camera(state->cam, state->map);
	if (ret)
		return (ret);
	ret = project_to_display(state->disp, state->cam);
	if (ret)
		return (ret);
	ret = putframe_display(state->disp, state->map);
	if (ret)
		return (ret);
	return (CODE_OK);
}
