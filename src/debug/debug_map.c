/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:38 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:39 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include <stdio.h>

static void	print_vertices(t_map *map)
{
	int	i;

	printf("%d vertices\n", map->n_v);
	i = 0;
	while (i < map->n_v)
	{
		printf("(%f, %f, %f) ", map->v[i].x, map->v[i].y, map->v[i].z);
		i++;
	}
	printf("\n");
}

static void	print_edges(t_map *map)
{
	int	i;

	printf("%d edges\n", map->n_e);
	i = 0;
	while (i < map->n_e)
	{
		printf("(%d -> %d) ", map->e[i].s, map->e[i].e);
		i++;
	}
	printf("\n");
}

void	print_map(t_map *map)
{
	if (!map)
	{
		printf("NULL map\n");
		return ;
	}
	printf("grid size: %f\n", map->grid_size);
	printf("%d x %d\n", map->n_col, map->n_row);
	print_vertices(map);
	print_edges(map);
	printf("x: (%f to %f)\n", map->x_bound[0], map->x_bound[1]);
	printf("y: (%f to %f)\n", map->y_bound[0], map->y_bound[1]);
	printf("z: (%f to %f)\n", map->z_bound[0], map->z_bound[1]);
}
