/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_putbuffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:44 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:45 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "display.h"
#include "mlx.h"

static int	start_buffer_display(t_display *disp)
{
	int	a[3];

	disp->img = mlx_new_image(disp->mlx, disp->w, disp->h);
	if (!disp->img)
		return (CODE_ERROR_IO);
	disp->img_addr = mlx_get_data_addr(disp->img, a, a + 1, a + 2);
	if (!disp->img_addr)
	{
		mlx_destroy_image(disp->mlx, disp->img);
		disp->img = NULL;
		return (CODE_ERROR_IO);
	}
	return (CODE_OK);
}

static int	end_buffer_display(t_display *disp)
{
	if (!disp->img)
		return (CODE_ERROR_GENERIC);
	mlx_clear_window(disp->mlx, disp->win);
	mlx_put_image_to_window(disp->mlx, disp->win, disp->img, 0, 0);
	mlx_destroy_image(disp->mlx, disp->img);
	disp->img = NULL;
	disp->img_addr = NULL;
	return (CODE_OK);
}

int	putframe_display(t_display *disp, t_map *map)
{
	int	i;
	int	ret;

	ret = start_buffer_display(disp);
	if (ret)
		return (ret);
	i = 0;
	while (i < map->n_e)
	{
		if (putline_display(disp, disp->v[map->e[i].s], disp->v[map->e[i].e]))
			break ;
		i++;
	}
	ret = end_buffer_display(disp);
	if (ret)
		return (ret);
	return (CODE_OK);
}
