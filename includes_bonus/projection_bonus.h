/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:01 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:04 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_BONUS_H
# define PROJECTION_BONUS_H
# include "geometry_bonus.h"
# include "display_bonus.h"

typedef struct s_camera
{
	t_matrix44	wtoc;
	int			n_v;
	t_vertex	*v;
	double		azi;
	double		ele;
	double		radius;
	double		step_a;
	double		step_d;
	double		fov;
}	t_camera;

t_camera	*create_camera(t_map *map);
void		del_camera(t_camera *cam);
void		refresh_camera(t_camera *cam);
void		increment_e_camera(t_camera *cam, int dir);
void		increment_a_camera(t_camera *cam, int dir);
void		increment_r_camera(t_camera *cam, int dir);

int			project_to_camera(t_camera *cam, t_map *map);
int			project_to_display(t_display *disp, t_camera *cam);
#endif
