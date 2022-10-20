#include "consts.h"
#include "camera.h"
#include "geometry.h"
#include <stdlib.h>

static void	refresh_camera(t_camera *cam)
{
	init_matrix44_identity(&cam->cam_to_world);
	init_matrix44_identity(&cam->world_to_cam);
	translate_matrix44_inplace(&cam->cam_to_world, g_r_cam, 0, 0);
	rotate_matrix44_inplace(&cam->cam_to_world, 1, -cam->elevation);
	rotate_matrix44_inplace(&cam->cam_to_world, 2, cam->azimuth);
	rotate_matrix44_inplace(&cam->world_to_cam, 2, -cam->azimuth);
	rotate_matrix44_inplace(&cam->world_to_cam, 1, cam->elevation);
	translate_matrix44_inplace(&cam->world_to_cam, -g_r_cam, 0, 0);
}

t_camera	*create_camera(void)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	if (!cam)
		return (NULL);
	cam->azimuth = 0;
	cam->elevation = 0;
	refresh_camera(cam);
	return (cam);
}

void	increment_e_camera(t_camera *cam, int dir)
{
	cam->elevation += g_cam_step_e * dir;
	refresh_camera(cam);
}

void	increment_a_camera(t_camera *cam, int dir)
{
	cam->elevation += g_cam_step_a * dir;
	refresh_camera(cam);
}

void	set_camera(t_camera *cam, double azimuth, double elevation)
{
	cam->azimuth = azimuth;
	cam->elevation = elevation;
	refresh_camera(cam);
}
