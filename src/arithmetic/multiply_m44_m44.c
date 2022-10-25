/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_m44_m44.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:24 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:26 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "geometry.h"

void	multiply_m44_m44(t_matrix44 *m_out, t_matrix44 *m_a, t_matrix44 *m_b)
{
	int		row;
	int		col;
	int		n;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			m_out->i[row][col] = 0;
			n = 0;
			while (n < 4)
			{
				m_out->i[row][col] += m_a->i[row][n] * m_b->i[n][col];
				n++;
			}
			col++;
		}
		row++;
	}
}

void	multiply_m44_m44_inplace(t_matrix44 *m_out, t_matrix44 *m)
{
	t_matrix44	temp;

	multiply_m44_m44(&temp, m, m_out);
	ft_memcpy(m_out, &temp, sizeof(t_matrix44));
}
