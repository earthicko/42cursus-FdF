#include "geometry.h"
#include <stdlib.h>

t_map	*init_map(int grid_size, int n_v, int n_e)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->grid_size = grid_size;
	map->n_v = n_v;
	map->v = malloc(sizeof(t_vertex) * n_v);
	map->n_e = n_e;
	map->e = malloc(sizeof(t_vertex) * n_e);
	return (map);
}

t_map	*make_cube(void)
{
	t_map	*map;

	map = init_map(10, 8, 12);

	map->v[0].x = -5;
	map->v[0].y = -5;
	map->v[0].z = -5;
	map->v[1].x = 5;
	map->v[1].y = -5;
	map->v[1].z = -5;
	map->v[2].x = 5;
	map->v[2].y = 5;
	map->v[2].z = -5;
	map->v[3].x = -5;
	map->v[3].y = 5;
	map->v[3].z = -5;
	map->v[4].x = -5;
	map->v[4].y = -5;
	map->v[4].z = 5;
	map->v[5].x = 5;
	map->v[5].y = -5;
	map->v[5].z = 5;
	map->v[6].x = 5;
	map->v[6].y = 5;
	map->v[6].z = 5;
	map->v[7].x = -5;
	map->v[7].y = 5;
	map->v[7].z = 5;

	map->e[0].s = 0;
	map->e[0].e = 1;
	map->e[1].s = 1;
	map->e[1].e = 2;
	map->e[2].s = 2;
	map->e[2].e = 3;
	map->e[3].s = 3;
	map->e[3].e = 0;
	map->e[4].s = 1;
	map->e[4].e = 5;
	map->e[5].s = 2;
	map->e[5].e = 6;
	map->e[6].s = 3;
	map->e[6].e = 7;
	map->e[7].s = 0;
	map->e[7].e = 4;
	map->e[8].s = 4;
	map->e[8].e = 5;
	map->e[9].s = 5;
	map->e[9].e = 6;
	map->e[10].s = 6;
	map->e[10].e = 7;
	map->e[11].s = 7;
	map->e[11].e = 4;

	map->x_bound[0] = -5;
	map->x_bound[1] = 5;
	map->y_bound[0] = -5;
	map->y_bound[1] = 5;
	map->z_bound[0] = -5;
	map->z_bound[1] = 5;

	return (map);
}
