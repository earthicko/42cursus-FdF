/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:11 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:16 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mlx_interface.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_state	*state;

	if (argc != 2)
		return (2);
	state = create_state(argv[1]);
	if (!state)
		return (2);
	mlx_hook(state->disp->win, ON_KEYUP, 0, mlx_key_interface, state);
	mlx_hook(state->disp->win, ON_DESTROY, 0, exit_program, state);
	mlx_loop(state->disp->mlx);
	return (0);
}
