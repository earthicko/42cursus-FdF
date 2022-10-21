#include "consts.h"
#include "projection.h"
#include "geometry.h"
#include <math.h>
#include <stdlib.h>

static void	refresh_camera(t_camera *cam)
{
	init_matrix44_identity(&cam->ctow);
	init_matrix44_identity(&cam->wtoc);
	rotate_matrix44_inplace(&cam->ctow, 1, M_PI_2);
	translate_matrix44_inplace(&cam->ctow, g_r_cam, 0, 0);
	rotate_matrix44_inplace(&cam->ctow, 1, -cam->elevation);
	rotate_matrix44_inplace(&cam->ctow, 2, cam->azimuth);
	rotate_matrix44_inplace(&cam->wtoc, 2, -cam->azimuth);
	rotate_matrix44_inplace(&cam->wtoc, 1, cam->elevation);
	translate_matrix44_inplace(&cam->wtoc, -g_r_cam, 0, 0);
	rotate_matrix44_inplace(&cam->wtoc, 1, -M_PI_2);
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
	cam->azimuth += g_cam_step_a * dir;
	refresh_camera(cam);
}

void	set_camera(t_camera *cam, double azimuth, double elevation)
{
	cam->azimuth = azimuth;
	cam->elevation = elevation;
	refresh_camera(cam);
}
