/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:43:08 by requinch          #+#    #+#             */
/*   Updated: 2022/07/26 11:51:13 by anbourge         ###   ########.fr       */
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
	int			pos[2];
	t_boolean	start_pt;

	pos[0] = 0;
	start_pt = FALSE;
	while (map[pos[0]])
	{
		pos[1] = 0;
		while (map[pos[0]][pos[1]])
		{
			printf("Debug : checking pos (%i,%i) : %c\n", pos[1], pos[0], map[pos[0]][pos[1]]);
			if ((map[pos[0]][pos[1]] == 'N' || map[pos[0]][pos[1]] == 'S'
				|| map[pos[0]][pos[1]] == 'E' || map[pos[0]][pos[1]] == 'W'))
			{
				if (start_pt == TRUE)
					return (FALSE);
				start_pt = TRUE;
			}
			if (check_map_character(map[pos[0]][pos[1]], 1) == FALSE)
				return (FALSE);
			pos[1] += 1;
		}
		pos[0] += 1;
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
