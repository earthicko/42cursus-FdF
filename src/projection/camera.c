#include "libft.h"
#include "consts.h"
#include "projection.h"
#include "geometry.h"
#include <math.h>
#include <stdlib.h>

// 월드에 동일한 좌표계 생성, 반지름만큼 평행이동, 2번 회전
static void	refresh_camera(t_camera *cam)
{
	t_vertex	temp;

	init_matrix44_identity(&cam->ctow);
	init_matrix44_identity(&cam->wtoc);
	rotate_m44_inplace(&cam->ctow, 1, M_PI_2);
	temp.x = cam->radius;
	temp.y = 0;
	temp.z = 0;
	translate_m44_inplace(&cam->ctow, &temp);
	rotate_m44_inplace(&cam->ctow, 1, cam->azimuth);
	rotate_m44_inplace(&cam->ctow, 2, -cam->elevation);
	rotate_m44_inplace(&cam->wtoc, 2, cam->elevation);
	rotate_m44_inplace(&cam->wtoc, 1, -cam->azimuth);
	temp.x = -cam->radius;
	translate_m44_inplace(&cam->wtoc, &temp);
	rotate_m44_inplace(&cam->wtoc, 1, -M_PI_2);
}

static double	get_initial_cam_radius(t_map *map)
{
	double	width;
	double	height;

	width = (map->x_bound[1] - map->x_bound[0]) / 2;
	height = (map->y_bound[1] - map->y_bound[0]) / 2;
	return (sqrt(width * width + height * height) * 8);
}

t_camera	*create_camera(t_map *map)
{
	t_camera	*cam;

	cam = (t_camera *)malloc(sizeof(t_camera));
	if (!cam)
		return (NULL);
	ft_memset(cam, 0, sizeof(t_camera));
	cam->azimuth = M_PI / 4;
	cam->elevation = M_PI / 4;
	cam->radius = get_initial_cam_radius(map);
	cam->step_d = cam->radius / 8;
	cam->step_a = M_PI / STEP_PER_ROTATION;
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
	cam->elevation += cam->step_a * dir;
	refresh_camera(cam);
}

void	increment_a_camera(t_camera *cam, int dir)
{
	cam->azimuth += cam->step_a * dir;
	refresh_camera(cam);
}

void	increment_r_camera(t_camera *cam, int dir)
{
	cam->radius += cam->step_d * dir;
	refresh_camera(cam);
}
