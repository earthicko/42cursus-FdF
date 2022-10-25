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
#include "display.h"
#include "geometry.h"
#include "projection.h"
#include "debug.h"
#include "consts.h"
#include "mlx_interface.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_state	*state;

	if (argc != 2)
		return (2);
	state = create_state(argv[1]);
	if (!state)
		return (2);
	mlx_key_hook(state->disp->win, mlx_key_interface, state);
	mlx_do_key_autorepeaton(state->disp->mlx);
	mlx_loop(state->disp->mlx);
	return (0);
}
