#include "libft.h"
#include "geometry.h"
#include <math.h>

void	translate_matrix44(t_matrix44 *out, t_matrix44 *m, double dx, double dy, double dz)
{
	t_matrix44	translate;

	init_matrix44_identity(&translate);
	translate.i[3][0] = dx;
	translate.i[3][1] = dy;
	translate.i[3][2] = dz;
	multiply_matrix44_matrix44(out, m, &translate);
}

void	translate_matrix44_inplace(t_matrix44 *m, double dx, double dy, double dz)
{
	t_matrix44	temp;

	translate_matrix44(&temp, m, dx, dy, dz);
	ft_memcpy(m, &temp, sizeof(t_matrix44));
}

void	scale_matrix44(t_matrix44 *out, t_matrix44 *m, double sx, double sy, double sz)
{
	t_matrix44	scale;

	init_matrix44_zero(&scale);
	scale.i[0][0] = sx;
	scale.i[1][1] = sy;
	scale.i[2][2] = sz;
	scale.i[3][3] = 1;
	multiply_matrix44_matrix44(out, m, &scale);
}

void	scale_matrix44_inplace(t_matrix44 *m, double dx, double dy, double dz)
{
	t_matrix44	temp;

	scale_matrix44(&temp, m, dx, dy, dz);
	ft_memcpy(m, &temp, sizeof(t_matrix44));
}

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
