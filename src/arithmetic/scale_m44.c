/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_m44.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:33 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:34 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "geometry.h"

void	scale_m44(t_matrix44 *out, t_matrix44 *m, t_vertex *scale)
{
	t_matrix44	scaler;

	init_matrix44_identity(&scaler);
	scaler.i[0][0] = scale->x;
	scaler.i[1][1] = scale->y;
	scaler.i[2][2] = scale->z;
	multiply_m44_m44(out, m, &scaler);
}

void	scale_m44_inplace(t_matrix44 *m, t_vertex *scale)
{
	t_matrix44	temp;

	scale_m44(&temp, m, scale);
	ft_memcpy(m, &temp, sizeof(t_matrix44));
}
