#ifndef DEBUG_H
# define DEBUG_H
# include "geometry.h"
# include "projection.h"

// 디버그용 함수들
void	print_matrix(t_matrix44 *m);
void	print_map(t_map *map);
void	print_camera(t_camera *cam);
#endif
