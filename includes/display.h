#ifndef DISPLAY_H
# define DISPLAY_H
# include "geometry.h"

typedef struct s_pixel
{
	int				x;
	int				y;
	unsigned int	color;
}	t_pixel;

typedef struct s_display
{
	int		bpp;
	int		nbytes;
	int		endian;
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		w;
	int		h;
	int		n_v;
	t_pixel	*v;
}	t_display;

t_display	*create_display(int width, int height, char *title);
int			start_buffer_display(t_display *disp);
int			putline_display(t_display *disp, t_pixel s, t_pixel e);
int			end_buffer_display(t_display *disp);
void		refresh_frame(t_display *disp, t_map *map);
#endif
