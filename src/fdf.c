#include "mlx.h"
#include "display.h"
#include "geometry.h"
#include "test.h"
#include "projection.h"
#include "debug.h"
#include "consts.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	t_map *map = make_cube();
	t_camera *cam = create_camera();
	t_display *disp = create_display(g_screen_w, g_screen_h, (char *)g_screen_title);

	increment_a_camera(cam, 1);
	increment_a_camera(cam, 1);
	increment_a_camera(cam, 1);
	increment_e_camera(cam, 1);

	print_camera(cam);
	project_to_camera(map, cam);
	project_to_screen(disp, map);
	refresh_frame(disp, map);

	mlx_loop(disp->mlx);
	return (0);
}
