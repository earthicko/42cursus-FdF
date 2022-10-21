#include "mlx.h"
#include "display.h"
#include "geometry.h"
#include "test.h"
#include "projection.h"
#include "debug.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	t_map *cube = make_cube();
	t_camera *cam = create_camera();
	t_display *disp = create_display(1000, 1000, "SuperTest");

	increment_a_camera(cam, 1);
	increment_a_camera(cam, 1);
	increment_a_camera(cam, 1);
	increment_e_camera(cam, 1);
	print_camera(cam);
	project_to_camera(cube, cam);
	project_to_display(disp, cube);
	putframe_display(disp, cube);

	mlx_loop(disp->mlx);
	return (0);
}
