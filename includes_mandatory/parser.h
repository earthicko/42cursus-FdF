/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:00 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:00 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "libft_def.h"
# include "geometry.h"

# define SPACE_CHARS " \r\n\t\v\f"
# define HEX_CHARS "0123456789abcdefABCDEF"

typedef struct s_vertexarr
{
	t_vertex	*data;
	int			cap;
	int			len;
}	t_vertexarr;

t_vertexarr	*create_vertexarr(int cap);
t_vertexarr	*del_vertexarr(t_vertexarr *arr);

t_vertexarr	*parse_line(char *line);
int			parse_map_info(t_map *map, int fd);
int			parse_map_content(t_map *map, int fd);
t_map		*parse_map(char *path);

#endif
