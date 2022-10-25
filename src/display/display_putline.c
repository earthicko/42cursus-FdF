/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_putline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:45 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:46 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "display.h"
#include <limits.h>

static void	putpixel_display(t_display *disp, t_pixel p)
{
	int	o_height;
	int	o_width;

	if (p.x < 0 || p.x >= disp->w)
		return ;
	if (p.y < 0 || p.y >= disp->h)
		return ;
	o_height = disp->nbytes * p.y;
	o_width = p.x * disp->bpp / 8;
	*(int *)(disp->img_addr + o_height + o_width) = 0xFFFFFFFF;
}

static void	putline_display_recur(t_display *disp, t_pixel s, t_pixel e)
{
	t_pixel	m;
	int		dx;
	int		dy;

	dx = s.x - e.x;
	dy = s.y - e.y;
	if (-1 <= dx && dx <= 1 && -1 <= dy && dy <= 1)
		return ;
	m.x = (s.x + e.x) / 2;
	m.y = (s.y + e.y) / 2;
	putpixel_display(disp, m);
	putline_display_recur(disp, s, m);
	putline_display_recur(disp, m, e);
}

static int	is_inf(t_pixel *s, t_pixel *e)
{
	if (s->x == INT_MAX || s->x == INT_MIN)
		return (1);
	if (s->y == INT_MAX || s->y == INT_MIN)
		return (1);
	if (e->x == INT_MAX || e->x == INT_MIN)
		return (1);
	if (e->y == INT_MAX || e->y == INT_MIN)
		return (1);
	return (0);
}

int	putline_display(t_display *disp, t_pixel s, t_pixel e)
{
	if (!disp->img)
		return (-1);
	if (is_inf(&s, &e))
		return (0);
	putpixel_display(disp, s);
	putpixel_display(disp, e);
	putline_display_recur(disp, s, e);
	return (0);
}
