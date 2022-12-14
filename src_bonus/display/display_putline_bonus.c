/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_putline_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:45 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:46 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_bonus.h"

static t_uint	avg_color(t_uint a, t_uint b)
{
	int		i;
	t_uint	out;
	t_uint	val;

	out = 0;
	i = 0;
	while (i < (int) sizeof(t_uint))
	{
		val = ((t_uint)((t_uchar *)(&a))[i] + (t_uint)((t_uchar *)(&b))[i]) / 2;
		((t_uchar *)(&out))[i] = (t_uchar)val;
		i++;
	}
	return (out);
}

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
	*(t_uint *)(disp->img_addr + o_height + o_width) = p.color;
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
	m.color = avg_color(s.color, e.color);
	putpixel_display(disp, s);
	putpixel_display(disp, e);
	putpixel_display(disp, m);
	putline_display_recur(disp, s, m);
	putline_display_recur(disp, m, e);
}

int	putline_display(t_display *disp, t_pixel s, t_pixel e)
{
	if (!disp->img)
		return (CODE_ERROR_GENERIC);
	putpixel_display(disp, s);
	putpixel_display(disp, e);
	putline_display_recur(disp, s, e);
	return (CODE_OK);
}
