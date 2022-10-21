#ifndef PROJECTION_H
# define PROJECTION_H
# include "geometry.h"
# include "display.h"

typedef struct s_camera
{
	t_matrix44	ctow;
	t_matrix44	wtoc;
	double		azimuth;
	double		elevation;
	double		fov;
}	t_camera;

t_camera	*create_camera(void);
void		increment_e_camera(t_camera *cam, int dir);
void		increment_a_camera(t_camera *cam, int dir);
void		set_camera(t_camera *cam, double azimuth, double elevation);

void		project_to_camera(t_map *map, t_camera *cam);
void		project_to_screen(t_display *disp, t_map *map);
#endif
