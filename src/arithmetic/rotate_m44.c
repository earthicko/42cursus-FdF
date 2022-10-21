#include "libft.h"
#include "geometry.h"
#include <math.h>

static void	rotate_matrix44_x(t_matrix44 *out, t_matrix44 *m, double theta)
{
	t_matrix44	rotate;

	init_matrix44_zero(&rotate);
	rotate.i[0][0] = 1;
	rotate.i[1][1] = cos(theta);
	rotate.i[1][2] = sin(theta);
	rotate.i[2][1] = -sin(theta);
	rotate.i[2][2] = cos(theta);
	rotate.i[3][3] = 1;
	multiply_matrix44_matrix44(out, m, &rotate);
}

static void	rotate_matrix44_y(t_matrix44 *out, t_matrix44 *m, double theta)
{
	t_matrix44	rotate;

	init_matrix44_zero(&rotate);
	rotate.i[0][0] = cos(theta);
	rotate.i[0][2] = -sin(theta);
	rotate.i[1][1] = 1;
	rotate.i[2][0] = sin(theta);
	rotate.i[2][2] = cos(theta);
	rotate.i[3][3] = 1;
	multiply_matrix44_matrix44(out, m, &rotate);
}

static void	rotate_matrix44_z(t_matrix44 *out, t_matrix44 *m, double theta)
{
	t_matrix44	rotate;

	init_matrix44_zero(&rotate);
	rotate.i[0][0] = cos(theta);
	rotate.i[0][1] = sin(theta);
	rotate.i[1][0] = -sin(theta);
	rotate.i[1][1] = cos(theta);
	rotate.i[2][2] = 1;
	rotate.i[3][3] = 1;
	multiply_matrix44_matrix44(out, m, &rotate);
}

void	rotate_matrix44(t_matrix44 *out, t_matrix44 *m, int i_axis, double theta)
{
	if (i_axis == 0)
		rotate_matrix44_x(out, m, theta);
	else if (i_axis == 1)
		rotate_matrix44_y(out, m, theta);
	else if (i_axis == 2)
		rotate_matrix44_z(out, m, theta);
}

void	rotate_matrix44_inplace(t_matrix44 *m, int i_axis, double theta)
{
	t_matrix44	temp;

	rotate_matrix44(&temp, m, i_axis, theta);
	ft_memcpy(m, &temp, sizeof(t_matrix44));
}
