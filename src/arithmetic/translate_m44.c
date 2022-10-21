#include "libft.h"
#include "geometry.h"

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
