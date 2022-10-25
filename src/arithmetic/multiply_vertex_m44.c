/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_vertex_m44.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:27 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:30 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

void	multiply_vertex_m44(t_vertex *out, t_vertex *v_a, t_matrix44 *m_b)
{
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
}
