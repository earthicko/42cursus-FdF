/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:49 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:50 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry_bonus.h"

void	init_matrix44_zero(t_matrix44 *m)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		m->i[i / 4][i % 4] = 0;
		i++;
	}
}

void	init_matrix44_identity(t_matrix44 *m)
{
	int	i;

	init_matrix44_zero(m);
	i = 0;
	while (i < 4)
	{
		m->i[i][i] = 1;
		i++;
	}
}
