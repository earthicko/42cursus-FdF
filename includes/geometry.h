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

void		init_matrix44_zero(t_matrix44 *m);
void		init_matrix44_identity(t_matrix44 *m);
t_matrix44	*create_matrix44(void);

void		multiply_vertex_matrix44(t_vertex *v_out, t_vertex *v_a, t_matrix44 *m_b);
void		multiply_vertex_matrix44_inplace(t_vertex *v_out, t_matrix44 *m);
void		multiply_matrix44_matrix44(t_matrix44 *m_out, t_matrix44 *m_a, t_matrix44 *m_b);
void		multiply_matrix44_matrix44_inplace(t_matrix44 *m_out, t_matrix44 *m);

void		translate_matrix44(t_matrix44 *out, t_matrix44 *m, double dx, double dy, double dz);
void		translate_matrix44_inplace(t_matrix44 *m, double dx, double dy, double dz);
void		scale_matrix44(t_matrix44 *out, t_matrix44 *m, double sx, double sy, double sz);
void		scale_matrix44_inplace(t_matrix44 *m, double dx, double dy, double dz);
void		rotate_matrix44(t_matrix44 *out, t_matrix44 *m, int i_axis, double theta);
void		rotate_matrix44_inplace(t_matrix44 *m, int i_axis, double theta);
#endif
