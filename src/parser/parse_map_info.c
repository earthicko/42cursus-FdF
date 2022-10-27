/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:55 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:56 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include <stdlib.h>

static int	determine_width(t_map *map, int fd)
{
	char		*first_line;
	t_intarr	*first_row;

	first_line = get_next_line(fd);
	if (!first_line)
		return (CODE_ERROR_IO);
	first_row = parse_line(first_line);
	free(first_line);
	if (!first_row)
		return (CODE_ERROR_GENERIC);
	map->n_col = first_row->len;
	del_intarr(first_row);
	return (CODE_OK);
}

static int	determine_height(t_map *map, int fd)
{
	char		*next_line;
	t_intarr	*next_row;
	int			n_row;
	int			n_col;

	n_row = 1;
	while (TRUE)
	{
		next_line = get_next_line(fd);
		if (!next_line)
		{
			map->n_row = n_row;
			return (CODE_OK);
		}
		next_row = parse_line(next_line);
		free(next_line);
		if (!next_row)
			return (CODE_ERROR_GENERIC);
		n_col = next_row->len;
		del_intarr(next_row);
		if (n_col != map->n_col)
			return (CODE_ERROR_GENERIC);
		n_row++;
	}
}

int	parse_map_info(t_map *map, int fd)
{
	if (determine_width(map, fd))
		return (CODE_ERROR_GENERIC);
	if (determine_height(map, fd))
		return (CODE_ERROR_GENERIC);
	map->n_v = map->n_row * map->n_col;
	map->n_e = (map->n_row - 1) * map->n_col + map->n_row * (map->n_col - 1);
	map->v = malloc(sizeof(t_vertex) * map->n_v);
	map->e = malloc(sizeof(t_edge) * map->n_e);
	if (!map->v || !map->e)
		return (CODE_ERROR_MALLOC);
	return (CODE_OK);
}
