/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epsilon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:22 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:23 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "consts.h"
#include "epsilon.h"

int	is_within_error(double a, double b)
{
	if (-EPSILON <= b - a && b - a <= EPSILON)
		return (1);
	return (0);
}
