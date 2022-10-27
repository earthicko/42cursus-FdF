/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_m44_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:31 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:32 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "geometry_bonus.h"
#include <math.h>

static void	rotate_matrix44_x(t_matrix44 *out, t_matrix44 *m, double theta)
{
	t_matrix44	rotate;

	init_matrix44_zero(&rotate);
	rotate.i[0][0] = 1;
	rotate.i[1][1] = cos(theta);
	rotate.i[1][2] = sin(theta);
	rotate.i[2][1] = -sin(theta);
	rotate.i[2][2] = cos(theta);
	rotate.i[3][3] = 1;
	multiply_m44_m44(out, m, &rotate);
}

static void	rotate_matrix44_y(t_matrix44 *out, t_matrix44 *m, double theta)
{
	t_matrix44	rotate;

	init_matrix44_zero(&rotate);
	rotate.i[0][0] = cos(theta);
	rotate.i[0][2] = -sin(theta);
	rotate.i[1][1] = 1;
	rotate.i[2][0] = sin(theta);
	rotate.i[2][2] = cos(theta);
	rotate.i[3][3] = 1;
	multiply_m44_m44(out, m, &rotate);
}

static void	rotate_matrix44_z(t_matrix44 *out, t_matrix44 *m, double theta)
{
	t_matrix44	rotate;

	init_matrix44_zero(&rotate);
	rotate.i[0][0] = cos(theta);
	rotate.i[0][1] = sin(theta);
	rotate.i[1][0] = -sin(theta);
	rotate.i[1][1] = cos(theta);
	rotate.i[2][2] = 1;
	rotate.i[3][3] = 1;
	multiply_m44_m44(out, m, &rotate);
}

void	rotate_m44(t_matrix44 *out, t_matrix44 *m, int axis_i, double theta)
{
	if (axis_i == AXIS_X)
		rotate_matrix44_x(out, m, theta);
	else if (axis_i == AXIS_Y)
		rotate_matrix44_y(out, m, theta);
	else if (axis_i == AXIS_Z)
		rotate_matrix44_z(out, m, theta);
}

void	rotate_m44_inplace(t_matrix44 *m, int axis_i, double theta)
{
	t_matrix44	temp;

	rotate_m44(&temp, m, axis_i, theta);
	ft_memcpy(m, &temp, sizeof(t_matrix44));
}
