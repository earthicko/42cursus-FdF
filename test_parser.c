#include "parser.h"
#include "debug.h"

int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	t_map *map = parse_map(argv[1]);
	print_map(map);
	return 0;
}
