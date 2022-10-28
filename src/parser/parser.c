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

#include "libft.h"
#include "ft_printf_def.h"
#include "consts.h"
#include "parser.h"
#include <fcntl.h>
#include <unistd.h>

static int	get_colorval(char *color, t_uchar *ret)
{
	if (!ft_strchr(HEX_CHARS, color[0]) || !ft_strchr(HEX_CHARS, color[-1]))
	{
		ft_dprintf(STDERR_FILENO,
			"parser: \"%s\" is not a valid color indicator\n", color);
		return (CODE_ERROR_DATA);
	}
	*ret = 0;
	if ('0' <= color[0] && color[0] <= '9')
		(*ret) += (color[0] - '0');
	else if ('a' <= color[0] && color[0] <= 'f')
		(*ret) += (color[0] - 'a' + 10);
	else
		(*ret) += (color[0] - 'A' + 10);
	if ('0' <= color[-1] && color[-1] <= '9')
		(*ret) += 16 * (color[-1] - '0');
	else if ('a' <= color[-1] && color[-1] <= 'f')
		(*ret) += 16 * (color[-1] - 'a' + 10);
	else
		(*ret) += 16 * (color[-1] - 'A' + 10);
	return (CODE_OK);
}

static int	fill_vertex_color_info(char *color, t_vertex *v)
{
	int		i;
	int		colorlen;
	t_uchar	colorval;

	colorlen = ft_strlen(color);
	if (ft_strncmp(color, "0x", 2) || colorlen > 10 || colorlen % 2 != 0)
	{
		ft_dprintf(STDERR_FILENO,
			"parser: \"%s\" is not a valid color indicator\n", color);
		return (CODE_ERROR_DATA);
	}
	v->color = 0;
	i = colorlen - 1;
	while (i >= 2)
	{
		if (get_colorval(color + i, &colorval))
			return (CODE_ERROR_DATA);
		v->color |= ((t_uint)colorval) << (colorlen - 1 - i) * 4;
		i -= 2;
	}
	return (CODE_OK);
}

int	parse_vertex(char *word, t_vertex *v)
{
	char	**words;
	int		wordslen;
	int		ret;

	words = ft_split(word, ',');
	if (!words)
		return (CODE_ERROR_MALLOC);
	wordslen = ft_strarrlen(words);
	if (wordslen > 2 || ft_atoi_if_valid(words[0], &ret))
	{
		ft_dprintf(STDERR_FILENO,
			"parser: \"%s\" is not a properly formatted vertex info\n", word);
		ft_free_strarr(words);
		return (CODE_ERROR_DATA);
	}
	v->z = ret;
	if (wordslen == 1)
	{
		v->color = COLOR_DEFAULT;
		ft_free_strarr(words);
		return (CODE_OK);
	}
	ret = fill_vertex_color_info(words[1], v);
	ft_free_strarr(words);
	return (ret);
}

t_vertexarr	*parse_line(char *line)
{
	t_vertexarr	*arr;
	char		**split;
	int			i;

	split = ft_split_by_chars(line, SPACE_CHARS);
	if (!split)
		return (NULL);
	arr = create_vertexarr(ft_strarrlen(split));
	if (!arr)
		return ((t_vertexarr *)ft_free_strarr(split));
	i = 0;
	while (i < arr->cap)
	{
		if (parse_vertex(split[i], &arr->data[i]))
		{
			ft_dprintf(STDERR_FILENO,
				"parser: error while parsing %s at col %d\n", split[i], i);
			ft_free_strarr(split);
			return (del_vertexarr(arr));
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
	ft_printf("parser: map %d x %d, xy grid size=%d\n",
		map->n_row, map->n_col, (int)(map->grid_size));
	ft_printf("parser: total %d vertices, %d edges\n", map->n_v, map->n_e);
	ft_printf("parser: x[%d, %d] y[%d, %d] z[%d, %d]\n",
		(int)map->x_bound[0], (int)map->x_bound[1],
		(int)map->y_bound[0], (int)map->y_bound[1],
		(int)map->z_bound[0], (int)map->z_bound[1]);
	return (map);
}
