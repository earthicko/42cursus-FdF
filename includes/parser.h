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

t_intarr	*parse_line(char *line);
int			parse_map_info(t_map *map, int fd);
int			parse_map_content(t_map *map, int fd);
t_map		*parse_map(char *path);

#endif
