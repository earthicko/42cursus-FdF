/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_interface.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:09:56 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:09:58 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INTERFACE_H
# define MLX_INTERFACE_H
# include "projection.h"

typedef struct s_state
{
	t_map		*map;
	t_camera	*cam;
	t_display	*disp;
}	t_state;

t_state	*create_state(char *map_path);
t_state	*del_state(t_state *state);
int		refresh_frame(t_state *state);
#endif
