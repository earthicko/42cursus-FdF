/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertexarr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:10:56 by donghyle          #+#    #+#             */
/*   Updated: 2022/10/25 16:10:57 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include <stdlib.h>

t_vertexarr	*create_vertexarr(int cap)
{
	t_vertexarr	*arr;

	arr = malloc(sizeof(t_vertexarr));
	if (!arr)
		return (NULL);
	arr->data = malloc(sizeof(t_vertex) * cap);
	if (!arr->data)
	{
		free(arr);
		return (NULL);
	}
	arr->cap = cap;
	arr->len = 0;
	return (arr);
}

t_vertexarr	*del_vertexarr(t_vertexarr *arr)
{
	free(arr->data);
	free(arr);
	return (NULL);
}
