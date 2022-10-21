#include "libft.h"
#include "geometry.h"

void	multiply_matrix44_matrix44(t_matrix44 *m_out, t_matrix44 *m_a, t_matrix44 *m_b)
{
	int		row;
	int		col;
	int		n;
	double	(*out)[4];
	double	(*a)[4];
	double	(*b)[4];

	out = m_out->i;
	a = m_a->i;
	b = m_b->i;
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			out[row][col] = 0;
			n = 0;
			while (n < 4)
			{
				out[row][col] += a[row][n] * b[n][col];
				n++;
			}
			col++;
		}
		row++;
	}
}

void	multiply_matrix44_matrix44_inplace(t_matrix44 *m_out, t_matrix44 *m)
{
	t_matrix44	temp;

	multiply_matrix44_matrix44(&temp, m, m_out);
	ft_memcpy(m_out, &temp, sizeof(t_matrix44));
}
