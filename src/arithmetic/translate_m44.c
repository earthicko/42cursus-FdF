#include "libft.h"
#include "geometry.h"

void	translate_m44(t_matrix44 *out, t_matrix44 *m, t_vertex *delta)
{
	t_matrix44	translate;

	init_matrix44_identity(&translate);
	translate.i[3][0] = delta->x;
	translate.i[3][1] = delta->y;
	translate.i[3][2] = delta->z;
	multiply_m44_m44(out, m, &translate);
}

void	translate_m44_inplace(t_matrix44 *m, t_vertex *delta)
{
	t_matrix44	temp;

	translate_m44(&temp, m, delta);
	ft_memcpy(m, &temp, sizeof(t_matrix44));
}
