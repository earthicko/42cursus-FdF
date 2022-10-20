#include "camera.h"
#include "debug.h"
#include <stdio.h>

int main()
{
	t_camera	*cam;

	cam = create_camera();
	print_camera(cam);

	increment_a_camera(cam, 1);
	increment_a_camera(cam, 1);
	increment_a_camera(cam, 1);
	increment_a_camera(cam, 1);
	increment_a_camera(cam, 1);
	increment_a_camera(cam, 1);
	increment_a_camera(cam, 1);
	increment_a_camera(cam, 1);
	increment_a_camera(cam, 1);
	printf("After increment azimuth +9\n");
	print_camera(cam);

	increment_a_camera(cam, -1);
	increment_a_camera(cam, -1);
	increment_a_camera(cam, -1);
	printf("After increment azimuth -3\n");
	print_camera(cam);

	increment_e_camera(cam, 1);
	increment_e_camera(cam, 1);
	increment_e_camera(cam, 1);
	printf("After increment elevation +3\n");
	print_camera(cam);
	
	return 0;
}
