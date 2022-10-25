/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:56 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:57 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

t_intarr	*parse_line(char *line)
{
	t_intarr	*arr;
	char		**split;
	int			i;

	split = ft_split_by_chars(line, SPACE_CHARS);
	if (!split)
		return (NULL);
	arr = create_intarr(ft_strarrlen(split));
	if (!arr)
		return ((t_intarr *)ft_free_strarr(split));
	i = 0;
	while (i < arr->cap)
	{
		if (ft_atoi_if_valid(split[i], &arr->data[i]))
		{
			ft_free_strarr(split);
			return (del_intarr(arr));
		}
		i++;
	}
	arr->len = arr->cap;
	ft_free_strarr(split);
	return (arr);
}

t_map	*parse_map(char *path)
{
	t_map	*map;
	int		fd;

	map = create_map();
	if (!map)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0 || parse_map_info(map, fd) || close(fd))
		return (del_map(map));
	fd = open(path, O_RDONLY);
	if (fd < 0 || parse_map_content(map, fd) || close(fd))
		return (del_map(map));
	return (map);
}
