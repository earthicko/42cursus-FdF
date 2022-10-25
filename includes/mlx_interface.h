#ifndef MLX_INTERFACE_H
# define MLX_INTERFACE_H
# include "projection.h"
# define KEYCODE_W 119
# define KEYCODE_A 97
# define KEYCODE_S 115
# define KEYCODE_D 100
# define KEYCODE_Q 113
# define KEYCODE_E 101

// mlx hook에 param으로 필요 변수를 한번에 전달하기 위한 구조체
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
