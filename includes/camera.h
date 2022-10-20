#ifndef CAMERA_H
# define CAMERA_H
# include "geometry.h"

typedef struct s_camera
{
	t_matrix44	cam_to_world;
	t_matrix44	world_to_cam;
	double		azimuth;
	double		elevation;
	double		fov;
}	t_camera;

t_camera	*create_camera(void);
void		increment_e_camera(t_camera *cam, int dir);
void		increment_a_camera(t_camera *cam, int dir);
void		set_camera(t_camera *cam, double azimuth, double elevation);
#endif
