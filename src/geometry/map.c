/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:47 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:48 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "geometry.h"
#include <stdlib.h>

t_map	*del_map(t_map *map)
{
	if (map->v)
		free(map->v);
	if (map->e)
		free(map->e);
	free(map);
	return (NULL);
}

t_map	*create_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	ft_memset(map, 0, sizeof(t_map));
	map->grid_size = 0.0;
	map->x_bound[0] = 0.0;
	map->x_bound[1] = 0.0;
	map->y_bound[0] = 0.0;
	map->y_bound[1] = 0.0;
	map->z_bound[0] = 0.0;
	map->z_bound[1] = 0.0;
	map->span = 0.0;
	return (map);
}

void	center_map(t_map *map)
{
	double	center[3];
	int		i;

	center[0] = (map->x_bound[1] + map->x_bound[0]) / 2;
	center[1] = (map->y_bound[1] + map->y_bound[0]) / 2;
	center[2] = (map->z_bound[1] + map->z_bound[0]) / 2;
	i = 0;
	while (i < map->n_v)
	{
		map->v[i].x -= center[0];
		map->v[i].y -= center[1];
		map->v[i].z -= center[2];
		i++;
	}
	map->x_bound[0] -= center[0];
	map->x_bound[1] -= center[0];
	map->y_bound[0] -= center[1];
	map->y_bound[1] -= center[1];
	map->z_bound[0] -= center[2];
	map->z_bound[1] -= center[2];
}
