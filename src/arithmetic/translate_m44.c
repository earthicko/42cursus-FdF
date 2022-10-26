/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_m44.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:34 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:36 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "geometry.h"

void	translate_m44_inplace(t_matrix44 *m, t_vertex *delta)
{
	t_matrix44	temp;
	t_matrix44	translate;

	init_matrix44_identity(&translate);
	translate.i[3][0] = delta->x;
	translate.i[3][1] = delta->y;
	translate.i[3][2] = delta->z;
	multiply_m44_m44(&temp, m, &translate);
	ft_memcpy(m, &temp, sizeof(t_matrix44));
}
