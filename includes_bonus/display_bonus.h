/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:09:45 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:09:46 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_BONUS_H
# define DISPLAY_BONUS_H
# include "geometry_bonus.h"

typedef struct s_pixel
{
	int				x;
	int				y;
	unsigned int	color;
}	t_pixel;

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
	int		n_v;
	t_pixel	*v;
}	t_display;

t_display	*create_display(int width, int height, char *title);
t_display	*del_display(t_display *disp);
int			putline_display(t_display *disp, t_pixel s, t_pixel e);
void		putframe_display(t_display *disp, t_map *map);
#endif
