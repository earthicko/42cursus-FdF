#include "geometry.h"
#include <stdio.h>

void	print_map(t_map *map)
{
	if (!map)
	{
		printf("NULL map\n");
		return ;
	}
	printf("grid size: %f\n", map->grid_size);
	printf("%d x %d\n", map->n_col, map->n_row);
	printf("%d vertices\n", map->n_v);
	for (int i = 0; i < map->n_v; i++)
		printf("(%f, %f, %f) ", map->v[i].x, map->v[i].y, map->v[i].z);
	printf("\n");
	printf("%d edges\n", map->n_e);
	for (int i = 0; i < map->n_e; i++)
		printf("(%d -> %d) ", map->e[i].s, map->e[i].e);
	printf("\n");
	printf("x: (%f to %f)\n", map->x_bound[0], map->x_bound[1]);
	printf("y: (%f to %f)\n", map->y_bound[0], map->y_bound[1]);
	printf("z: (%f to %f)\n", map->z_bound[0], map->z_bound[1]);
}
