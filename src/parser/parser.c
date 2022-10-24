#include "libft.h"
#include "parser.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

t_map	*parse_map(char *path)
{
	t_map	*map;
	int		fd;

	map = create_map();
	if (!map)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (del_map(map));
	if (parse_map_info(map, fd))
		return (del_map(map));
	if (close(fd))
		return (del_map(map));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (del_map(map));
	if (parse_map_content(map, fd))
		return (del_map(map));
	if (close(fd))
		return (del_map(map));
	return (map);
}
