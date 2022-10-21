#include "debug.h"
#include "projection.h"
#include <stdio.h>
#include <math.h>

void	print_camera(t_camera *cam)
{
	printf("azimuth %f deg, elevation %f deg\n",
		cam->azimuth * 180.0 / M_PI, cam->elevation * 180.0 / M_PI);
	printf("Cam -> World\n");
	print_matrix(&cam->ctow);
	printf("World -> Cam\n");
	print_matrix(&cam->wtoc);
}
