#ifndef PARSER_H
# define PARSER_H
# include "libft.h"
# include "geometry.h"
# define SPACE_CHARS " \r\n\t\v\f"

t_intarr	*parse_line(char *line);
int			parse_map_info(t_map *map, int fd);
int			parse_map_content(t_map *map, int fd);
t_map		*parse_map(char *path);
#endif
