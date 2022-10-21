#include "libft.h"
#include "geometry.h"

void	scale_matrix44(t_matrix44 *out, t_matrix44 *m, double sx, double sy, double sz)
{
	t_matrix44	scale;

	init_matrix44_identity(&scale);
	scale.i[0][0] = sx;
	scale.i[1][1] = sy;
	scale.i[2][2] = sz;
	multiply_matrix44_matrix44(out, m, &scale);
}

void	scale_matrix44_inplace(t_matrix44 *m, double dx, double dy, double dz)
{
	t_matrix44	temp;

	scale_matrix44(&temp, m, dx, dy, dz);
	ft_memcpy(m, &temp, sizeof(t_matrix44));
}
