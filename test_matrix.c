#include "debug.h"
#include <stdio.h>
#include <math.h>

int main()
{
	t_matrix44 cam;
	t_matrix44 cam_;
	init_matrix44_identity(&cam);
	init_matrix44_identity(&cam_);
	print_matrix(&cam);

	printf("===========================\n");

	translate_m44_inplace(&cam, 10, 15, 20);
	printf("after translate:\n");
	print_matrix(&cam);

	scale_m44_inplace(&cam, 3, 2, 1);
	printf("after scale:\n");
	print_matrix(&cam);

	rotate_m44_inplace(&cam, 2, M_PI / 3);
	printf("after rotate:\n");
	print_matrix(&cam);

	printf("===========================\n");

	rotate_m44_inplace(&cam_, 2, -M_PI / 3);
	printf("after rotate:\n");
	print_matrix(&cam_);

	scale_m44_inplace(&cam_, 1.0 / 3.0, 1.0 / 2.0, 1.0);
	printf("after scale:\n");
	print_matrix(&cam_);

	translate_m44_inplace(&cam_, -10, -15, -20);
	printf("after translate:\n");
	print_matrix(&cam_);

	printf("===========================\n");

	t_matrix44 iden;
	multiply_m44_m44(&iden, &cam, &cam_);
	print_matrix(&iden);

	return (0);
}
