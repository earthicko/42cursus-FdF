/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_content_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:53 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:54 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "consts_bonus.h"
#include "parser_bonus.h"
#include "consts_bonus.h"
#include <limits.h>
#include <math.h>
#include <stdlib.h>

static void	determine_xyz_bound_grid_size(t_map *map)
{
	int	i;

	map->z_bound[0] = __DBL_MAX__;
	map->z_bound[1] = __DBL_MIN__;
	i = 0;
	while (i < map->n_v)
	{
		if (map->v[i].z < map->z_bound[0])
			map->z_bound[0] = map->v[i].z;
		if (map->v[i].z > map->z_bound[1])
			map->z_bound[1] = map->v[i].z;
		i++;
	}
	map->grid_size = (map->z_bound[1] - map->z_bound[0]) / GRID_SCALE;
	if (map->grid_size < RESOLUTION)
		map->grid_size = 1;
	map->x_bound[0] = 0;
	map->x_bound[1] = map->grid_size * (map->n_col - 1);
	map->y_bound[0] = 0;
	map->y_bound[1] = map->grid_size * (map->n_row - 1);
	map->span = sqrt(pow(map->x_bound[1], 2) + pow(map->y_bound[1], 2));
}

static void	fill_xy(t_map *map)
{
	int	i_row;
	int	i_col;

	i_row = 0;
	while (i_row < map->n_row)
	{
		i_col = 0;
		while (i_col < map->n_col)
		{
			map->v[map->n_col * i_row + i_col].x = i_col * map->grid_size;
			map->v[map->n_col * i_row + i_col].y = i_row * map->grid_size;
			i_col++;
		}
		i_row++;
	}
}

static void	fill_edge_s_e(t_map *map)
{
	int	i_row;
	int	i_col;
	int	i_e_hori;
	int	i_e_vert;

	i_e_hori = 0;
	i_e_vert = map->n_e - 1;
	i_row = -1;
	while (++i_row < map->n_row)
	{
		i_col = -1;
		while (++i_col < map->n_col)
		{
			if (i_col != map->n_col - 1)
			{
				map->e[i_e_hori].s = map->n_col * i_row + i_col;
				map->e[i_e_hori++].e = map->n_col * i_row + i_col + 1;
			}
			if (i_row != map->n_row - 1)
			{
				map->e[i_e_vert].s = map->n_col * i_row + i_col;
				map->e[i_e_vert--].e = map->n_col * (i_row + 1) + i_col;
			}
		}
	}
}

int	parse_map_content(t_map *map, int fd)
{
	int			i_row;
	char		*line;
	t_vertexarr	*row;

	i_row = 0;
	while (i_row < map->n_row)
	{
		line = get_next_line(fd);
		if (!line)
			return (CODE_ERROR_IO);
		row = parse_line(line);
		free(line);
		if (!row)
			return (CODE_ERROR_MALLOC);
		ft_memcpy(map->v + (i_row * map->n_col), row->data,
			sizeof(t_vertex) * row->len);
		del_vertexarr(row);
		ft_printf("\rparser: parsing line %d...", i_row);
		i_row++;
	}
	ft_printf("\n");
	determine_xyz_bound_grid_size(map);
	fill_xy(map);
	fill_edge_s_e(map);
	return (CODE_OK);
}
