#ifndef MLX_INTERFACE_H
# define MLX_INTERFACE_H
# include "projection.h"

typedef struct s_state
{
	t_map		*map;
	t_camera	*cam;
	t_display	*disp;
}	t_state;

t_state	*create_state(void);
void	refresh_frame(t_state *state);
int		mlx_key_interface(int keycode, void *param);
#endif
