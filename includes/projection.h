#ifndef PROJECTION_H
# define PROJECTION_H
# include "geometry.h"
# include "display.h"

typedef struct s_camera
{
	t_matrix44	ctow;
	t_matrix44	wtoc;
	int			n_v;
	t_vertex	*v;
	double		azimuth;
	double		elevation;
	double		fov;
}	t_camera;

t_camera	*create_camera(void);
void		del_camera(t_camera *cam);
void		increment_e_camera(t_camera *cam, int dir);
void		increment_a_camera(t_camera *cam, int dir);
void		set_camera(t_camera *cam, double azimuth, double elevation);

int			project_to_camera(t_camera *cam, t_map *map);
int			project_to_display(t_display *disp, t_camera *cam);
#endif
