#ifndef GEOMETRY_H
# define GEOMETRY_H

typedef struct s_vertex
{
	double	x;
	double	y;
	double	z;
}	t_vertex;

typedef struct s_edge
{
	t_vertex	*s;
	t_vertex	*e;
}	t_edge;

typedef struct s_matrix44
{
	double	i[4][4];
}	t_matrix44;

void	vertex_matrix44_multiply(t_vertex *v_out, t_vertex *v_a, t_matrix44 *m_b);
void	matrix44_matrix44_multiply(t_matrix44 *m_out, t_matrix44 *m_a, t_matrix44 *m_b);
#endif
