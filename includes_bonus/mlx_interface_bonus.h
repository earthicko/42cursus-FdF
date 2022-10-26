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
# include "display_bonus.h"
# define KEYCODE_ESC 53
# define KEYCODE_Q 12
# define KEYCODE_W 13
# define KEYCODE_E 14
# define KEYCODE_A 0
# define KEYCODE_S 1
# define KEYCODE_D 2
# define KEYCODE_I 34
# define KEYCODE_J 38
# define KEYCODE_K 40
# define KEYCODE_L 37
# define KEYCODE_SP 49
# define KEYCODE_PLUS 69
# define KEYCODE_MINUS 78

enum	e_appkitevent{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

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
int		exit_program(void *param);
#endif
