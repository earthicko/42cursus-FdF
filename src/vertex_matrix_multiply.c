#include "libft.h"
#include "geometry.h"
#include "epsilon.h"

void	multiply_vertex_matrix44(t_vertex *v_out, t_vertex *v_a, t_matrix44 *m_b)
{
	double	w;
	double	(*m)[4];
	double	x;
	double	y;
	double	z;

	m = m_b->i;
	x = v_a->x;
	y = v_a->y;
	z = v_a->z;
	v_out->x = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
	v_out->y = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
	v_out->z = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
	w = x * m[0][3] + y * m[1][3] + z * m[2][3] + m[3][3];
	if (!is_within_error(w, 1.0))
	{
		v_out->x /= w;
		v_out->y /= w;
		v_out->z /= w;
	}
}

void	multiply_vertex_matrix44_inplace(t_vertex *v_out, t_matrix44 *m)
{
	t_vertex	temp;

	multiply_vertex_matrix44(&temp, v_out, m);
	ft_memcpy(v_out, &temp, sizeof(t_vertex));
}
