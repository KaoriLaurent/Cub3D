/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:43:08 by requinch          #+#    #+#             */
/*   Updated: 2022/07/09 00:34:47 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned int	get_max_length(char **map) // Might wanna move this
{
	t_resolution	pos;
	unsigned int	save;


	pos.height = 0;
	save = 0;
	while (map[pos.height])
	{
		pos.width = 0;
		while (map[pos.height][pos.width])
			pos.width += 1;
		if (pos.width > save) 
			save = pos.width;
		pos.height += 1;
	}
	return (save);
}

/*
**	Mode	:	1 : All
**				2 : '1'
*/

t_boolean	check_map_character(char c, int mode)
{
	if (c == '1')
		return (TRUE);
	if (mode == 1)
		if (c == 32 || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
			return (TRUE);
	return (FALSE);
}

t_boolean	check_general(char **map)
{
	t_position	pos;

	pos.y = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (check_map_character(map[pos.y][pos.x], 1) == FALSE)
				return (FALSE);
			pos.x += 1;
		}
		pos.y += 1;
	}
	return (TRUE);
}

unsigned short	check_the_map(char **map)
{
//	t_position	pos;
//	t_vector	direction;

	if (check_general(map) == FALSE || map[0][0] != '1'
		|| map[1][0] != '1' || map[0][1] != '1')
		return (2);
	return (1);
/*	pos.x = 1;
	pos.y = 1;
	direction.x = 1;
	direction.y = 0;
	if (check_map_character(map[pos.y][pos.x], 1) == FALSE)
		return (2);
	if (check_map_character(map[pos.y][pos.x], 2) == FALSE)*/
}
