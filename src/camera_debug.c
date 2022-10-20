#include "debug.h"
#include "camera.h"
#include <stdio.h>
#include <math.h>

void	print_camera(t_camera *cam)
{
	printf("azimuth %f deg, elevation %f deg\n", cam->azimuth * 180.0 / M_PI, cam->elevation * 180.0 / M_PI);
	printf("Cam -> World\n");
	print_matrix(&cam->cam_to_world);
	printf("World -> Cam\n");
	print_matrix(&cam->world_to_cam);
	t_matrix44	mul;
	multiply_matrix44_matrix44(&mul, &cam->cam_to_world, &cam->world_to_cam);
	printf("Multiplied\n");
	print_matrix(&mul);
}
