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
	return (map);
}
