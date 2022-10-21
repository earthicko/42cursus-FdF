#include "consts.h"
#include "epsilon.h"

int	is_within_error(double a, double b)
{
	if (-EPSILON <= b - a && b - a <= EPSILON)
		return (1);
	return (0);
}
