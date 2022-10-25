/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_interface_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:09:56 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:09:58 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INTERFACE_BONUS_H
# define MLX_INTERFACE_BONUS_H
# include "projection_bonus.h"
# ifdef BUILD_X11
// X11 Keycodes
#  define KEYCODE_Q 113
#  define KEYCODE_W 119
#  define KEYCODE_E 101
#  define KEYCODE_A 97
#  define KEYCODE_S 115
#  define KEYCODE_D 100
# endif
# ifdef BUILD_APPKIT
// AppKit Keycodes
#  define KEYCODE_Q 12
#  define KEYCODE_W 13
#  define KEYCODE_E 14
#  define KEYCODE_A 0
#  define KEYCODE_S 1
#  define KEYCODE_D 2
# endif

typedef struct s_state
{
	t_map		*map;
	t_camera	*cam;
	t_display	*disp;
}	t_state;

t_state	*create_state(char *map_path);
t_state	*del_state(t_state *state);
int		refresh_frame(t_state *state);
int		mlx_key_interface(int keycode, void *param);
#endif
