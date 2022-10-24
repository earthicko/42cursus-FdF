#ifndef DISPLAY_H
# define DISPLAY_H
# include "geometry.h"

typedef struct s_pixel
{
	int				x;
	int				y;
	unsigned int	color;
}	t_pixel;

// mlx와 인터페이스 시 필요한 img 관련 int 3개, 각종 포인터, 디스플레이 속성
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
t_display	*del_display(t_display *disp);
int			putline_display(t_display *disp, t_pixel s, t_pixel e);
void		putframe_display(t_display *disp, t_map *map);
#endif
