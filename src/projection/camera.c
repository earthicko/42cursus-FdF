#include "libft.h"
#include "consts.h"
#include "projection.h"
#include "geometry.h"
#include <math.h>
#include <stdlib.h>

static void	refresh_camera(t_camera *cam)
{
	t_vertex	temp;

	init_matrix44_identity(&cam->ctow);
	init_matrix44_identity(&cam->wtoc);
	rotate_m44_inplace(&cam->ctow, 1, M_PI_2);
	temp.x = R_CAM;
	temp.y = 0;
	temp.z = 0;
	translate_m44_inplace(&cam->ctow, &temp);
	rotate_m44_inplace(&cam->ctow, 1, cam->azimuth);
	rotate_m44_inplace(&cam->ctow, 2, -cam->elevation);
	rotate_m44_inplace(&cam->wtoc, 2, cam->elevation);
	rotate_m44_inplace(&cam->wtoc, 1, -cam->azimuth);
	temp.x = -R_CAM;
	translate_m44_inplace(&cam->wtoc, &temp);
	rotate_m44_inplace(&cam->wtoc, 1, -M_PI_2);
}

t_camera	*create_camera(void)
{
	t_camera	*cam;

	cam = (t_camera *)malloc(sizeof(t_camera));
	if (!cam)
		return (NULL);
	ft_memset(cam, 0, sizeof(t_camera));
	refresh_camera(cam);
	return (cam);
}

void	del_camera(t_camera *cam)
{
	if (cam->v)
		free(cam->v);
	free(cam);
}

void	increment_e_camera(t_camera *cam, int dir)
{
	cam->elevation += CAM_STEP_E * dir;
	refresh_camera(cam);
}

void	increment_a_camera(t_camera *cam, int dir)
{
	cam->azimuth += CAM_STEP_A * dir;
	refresh_camera(cam);
}
