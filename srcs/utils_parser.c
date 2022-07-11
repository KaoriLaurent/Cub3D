/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:43:08 by requinch          #+#    #+#             */
/*   Updated: 2022/07/09 17:48:31 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
**	Mode	:	1 : All
**				2 : '1'
*/

t_boolean	check_map_character(char c, int mode)
{
	if (mode == 2 && c == '1')
		return (TRUE);
	else if (mode == 1 && (c == 32 || c == '0' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == '1'))
		return (TRUE);
	return (FALSE);
}

t_boolean	check_general(char **map)
{
	t_position	pos;
	t_boolean	start_pt;

	pos.y = 0;
	start_pt = FALSE;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			printf("Debug : checking pos (%i,%i) : %c\n", pos.x, pos.y, map[pos.y][pos.x]);
			if ((map[pos.y][pos.x] == 'N' || map[pos.y][pos.x] == 'S'
				|| map[pos.y][pos.x] == 'E' || map[pos.y][pos.x] == 'W'))
			{
				if (start_pt == TRUE)
					return (FALSE);
				start_pt = TRUE;
			}
			if (check_map_character(map[pos.y][pos.x], 1) == FALSE)
				return (FALSE);
			pos.x += 1;
		}
		pos.y += 1;
	}
	return (start_pt);
}

unsigned short	check_the_map(char **map)
{
/*	t_position	pos;
	t_vector	direction;*/

	if (check_general(map) == FALSE)
		return (free_map(map, 2));
	/* Algo
	pos.x = 0;
	pos.y = 0;
	direction.x = 1;
	direction.y = 0;
	if (check_map_character(map[pos.y][pos.x], 2) == FALSE)
	 End algo */
	return (free_map(map, 1));
}
