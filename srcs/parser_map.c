/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:43:08 by requinch          #+#    #+#             */
/*   Updated: 2022/08/23 16:39:10 by anbourge         ###   ########.fr       */
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

t_vector	get_starting_pos(char **map)
{
	t_vector	pos;

	pos.x = 0;
	pos.y = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] == 'N' || map[pos.y][pos.x] == 'S'
				|| map[pos.y][pos.x] == 'E' || map[pos.y][pos.x] == 'W')
				return (pos);
			pos.x += 1;
		}
		pos.y += 1;
	}
	return (pos);
}

t_boolean	recursive_check(char **map, t_vector pos, t_counter step)
{
	if ((map[pos.y][pos.x] == '0' || map[pos.y][pos.x] == 'N'
		|| map[pos.y][pos.x] == 'S' || map[pos.y][pos.x] == 'E'
			|| map[pos.y][pos.x] == 'W' || map[pos.y][pos.x] == ' ')
		&& is_edge(map, pos))
		return (FALSE);
	if (map[pos.y][pos.x] == '1' || map[pos.y][pos.x] == '2')
		return (TRUE);
	if (step == 400)
		return (TRUE);
	if (map[pos.y][pos.x] == '0' || map[pos.y][pos.x] == 'N'
		|| map[pos.y][pos.x] == 'S' || map[pos.y][pos.x] == 'E'
			|| map[pos.y][pos.x] == 'W' || map[pos.y][pos.x] == ' ')
	{
		map[pos.y][pos.x] = '2';
		if (recursive_check(map, shift_east(pos), step + 1) == FALSE
			|| recursive_check(map, shift_south(pos), step + 1) == FALSE
			|| recursive_check(map, shift_west(pos), step + 1) == FALSE
			|| recursive_check(map, shift_north(pos), step + 1) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

unsigned short	check_the_map(char **map, t_size height)
{
	t_vector	pos;

	if (height < 2 || check_general(map) == FALSE)
		return (free_text(map, 2));
	pos = get_starting_pos(map);
	if (recursive_check(map, pos, 0) == FALSE)
		return (free_text(map, 2));
	return (free_text(map, 1));
}
