#include "debug.h"
#include <stdio.h>

void	print_matrix(t_matrix44 *m)
{
	for (int i = 0; i < 4; i++)
	{
		printf("| ");
		for (int j = 0; j < 4; j++)
			printf("%10.5f ", m->i[i][j]);
		printf("|\n");
	}
}
