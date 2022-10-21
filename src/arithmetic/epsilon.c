#include "consts.h"
#include "epsilon.h"

int	is_within_error(double a, double b)
{
	if (-g_epsilon <= b - a && b - a <= g_epsilon)
		return (1);
	return (0);
}
