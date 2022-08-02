/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 00:39:27 by requinch          #+#    #+#             */
/*   Updated: 2022/08/01 04:57:26 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_boolean	is_edge(char **map, t_vector pos)
{
	if (pos.x == 0 || pos.y == 0
		|| !map[pos.y][pos.x + 1] || !map[pos.y + 1])
		return (TRUE);
	return (FALSE);
}

t_vector	shift_north(t_vector pos)
{
	pos.y -= 1;
	return (pos);
}

t_vector	shift_south(t_vector pos)
{
	pos.y += 1;
	return (pos);
}

t_vector	shift_west(t_vector pos)
{
	pos.x -= 1;
	return (pos);
}

t_vector	shift_east(t_vector pos)
{
	pos.x += 1;
	return (pos);
}
