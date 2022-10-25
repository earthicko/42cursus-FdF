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
#include "geometry.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

// putframe_display 호출 전 반드시 호출해야 하는 함수
static int	start_buffer_display(t_display *disp)
{
	int	a[3];

	disp->img = mlx_new_image(disp->mlx, disp->w, disp->h);
	if (!disp->img)
		return (-1);
	disp->img_addr = mlx_get_data_addr(disp->img, a, a + 1, a + 2);
	return (0);
}

// 그릴 내용을 모두 그린 후 호출하여 이미지 삭제 및 실제로 내용을 출력
static int	end_buffer_display(t_display *disp)
{
	if (!disp->img)
		return (-1);
	mlx_clear_window(disp->mlx, disp->win);
	mlx_put_image_to_window(disp->mlx, disp->win, disp->img, 0, 0);
	mlx_destroy_image(disp->mlx, disp->img);
	disp->img = NULL;
	return (0);
}

// map에 저장된 모든 edge를 이미지에 기록
void	putframe_display(t_display *disp, t_map *map)
{
	int		i;
	t_pixel	s;
	t_pixel	e;

	start_buffer_display(disp);
	i = 0;
	while (i < map->n_e)
	{
		ft_memcpy(&s, &disp->v[map->e[i].s], sizeof(t_pixel));
		ft_memcpy(&e, &disp->v[map->e[i].e], sizeof(t_pixel));
		putline_display(disp, s, e);
		i++;
	}
	end_buffer_display(disp);
}
