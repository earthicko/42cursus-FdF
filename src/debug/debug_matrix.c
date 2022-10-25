/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:40 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:42 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include <stdio.h>

void	print_matrix(t_matrix44 *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		printf("| ");
		j = 0;
		while (j < 4)
		{
			printf("%10.5f ", m->i[i][j]);
			j++;
		}
		printf("|\n");
		i++;
	}
}
