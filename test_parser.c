#include "geometry.h"
#include "debug.h"

int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	t_map *map = create_map();
	print_map(map);
	return 0;
}
