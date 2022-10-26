/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:09:45 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:09:46 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H
# include "geometry.h"
# define CAMMODE_ISOMETRIC 0
# define CAMMODE_PERSPECTIVE 1
# define CAMMODE_MAX CAMMODE_PERSPECTIVE

typedef struct s_pixel
{
	int				x;
	int				y;
	unsigned int	color;
}	t_pixel;

typedef struct s_camera
{
	int			mode;
	t_matrix44	wtoc;
	int			n_v;
	t_vertex	*v;
	int			*is_visible;
	double		min_z;
	t_vertex	orig;
	double		azi;
	double		ele;
	double		step_a;
	double		step_d;
	double		isometric_d;
}	t_camera;

typedef struct s_display
{
	int		bpp;
	int		nbytes;
	int		endian;
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		w;
	int		h;
	double	ratio;
	int		n_v;
	t_pixel	*v;
}	t_display;

t_camera	*create_camera(t_map *map);
void		del_camera(t_camera *cam);
void		refresh_camera(t_camera *cam);
void		increment_e_camera(t_camera *cam, int dir);
void		increment_a_camera(t_camera *cam, int dir);
void		increment_xyz_camera(t_camera *cam, int axis, int dir);
void		switch_projection_mode(t_camera *cam);

t_display	*create_display(int width, int height, char *title);
t_display	*del_display(t_display *disp);
int			putline_display(t_display *disp, t_pixel s, t_pixel e);

int			project_to_camera(t_camera *cam, t_map *map);
int			project_to_display(t_display *disp, t_camera *cam);
void		putframe_display(t_display *disp, t_camera *cam, t_map *map);
#endif
