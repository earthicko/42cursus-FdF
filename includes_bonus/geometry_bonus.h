/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:09:49 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:09:50 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_BONUS_H
# define GEOMETRY_BONUS_H

typedef struct s_vertex
{
	double	x;
	double	y;
	double	z;
}	t_vertex;

typedef struct s_edge
{
	int	s;
	int	e;
}	t_edge;

typedef struct s_matrix44
{
	double	i[4][4];
}	t_matrix44;

typedef struct s_map
{
	double		grid_size;
	int			n_row;
	int			n_col;
	int			n_v;
	t_vertex	*v;
	int			n_e;
	t_edge		*e;
	double		x_bound[2];
	double		y_bound[2];
	double		z_bound[2];
	double		span;
}	t_map;

void		init_matrix44_zero(t_matrix44 *m);
void		init_matrix44_identity(t_matrix44 *m);
t_matrix44	*create_matrix44(void);

void		multiply_vertex_m44(t_vertex *out, t_vertex *a, t_matrix44 *b);
void		multiply_m44_m44(t_matrix44 *out, t_matrix44 *a, t_matrix44 *b);
void		multiply_m44_m44_inplace(t_matrix44 *out, t_matrix44 *m);

void		translate_m44_inplace(t_matrix44 *m, t_vertex *delta);
void		scale_m44(t_matrix44 *out, t_matrix44 *m, t_vertex *scale);
void		scale_m44_inplace(t_matrix44 *m, t_vertex *scale);
void		rotate_m44(t_matrix44 *out, t_matrix44 *m, int xyz, double theta);
void		rotate_m44_inplace(t_matrix44 *m, int xyz, double theta);

t_map		*create_map(void);
t_map		*del_map(t_map *map);
void		center_map(t_map *map);
void		scale_z_map(t_map *map, double scale);
#endif
