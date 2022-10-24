#include "libft.h"
#include "geometry.h"
#include "epsilon.h"

// (x, y, z, w) 4차원 점을 곱하는 것을 가정하지만 w는 항상 1이어야 함 (아닐 시 스케일)
void	multiply_vertex_m44(t_vertex *out, t_vertex *v_a, t_matrix44 *m_b)
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
	out->x = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
	out->y = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
	out->z = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
	w = x * m[0][3] + y * m[1][3] + z * m[2][3] + m[3][3];
	if (!is_within_error(w, 1.0))
	{
		out->x /= w;
		out->y /= w;
		out->z /= w;
	}
}

void	multiply_vertex_m44_inplace(t_vertex *v_out, t_matrix44 *m)
{
	t_vertex	temp;

	multiply_vertex_m44(&temp, v_out, m);
	ft_memcpy(v_out, &temp, sizeof(t_vertex));
}
