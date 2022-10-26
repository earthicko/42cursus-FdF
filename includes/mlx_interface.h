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
# include "display.h"
# if !defined(BUILD_X11) && !defined(BUILD_APPKIT)
#  define BUILD_APPKIT
# endif
# ifdef BUILD_X11
// X11 Keycodes
# endif
# ifdef BUILD_APPKIT
// AppKit Keycodes
#  define KEYCODE_ESC 53
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
