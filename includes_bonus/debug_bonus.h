/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:09:44 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:09:44 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_BONUS_H
# define DEBUG_BONUS_H
# include "geometry_bonus.h"
# include "projection_bonus.h"

void	print_matrix(t_matrix44 *m);
void	print_map(t_map *map);
void	print_camera(t_camera *cam);
#endif
