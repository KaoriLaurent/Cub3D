/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:54:00 by requinch          #+#    #+#             */
/*   Updated: 2022/07/07 00:54:00 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
**	Return	:	-1 when invalid
**				0 when skip line
**				1 when proper line parsed
*/

short	parse_next_line(char *cub_raw, t_counter step)
{

}

/*
**	Step	:		0 - 3	:	paths to NSEW textures
**					4 - 5	:	RGB colors of floor and ceiling
**					6		:	map
**					7		:	check no bullshit after map
*/

t_boolean	parsing(char *filepath)
{
	t_boolean	checklist[7];
	t_counter	step;
	int	fd;
	short	last;

	step = 0;
	while (step < 8)
	{
		last = parse_next_line(fd, step);
		if (last < 0)
		{
			throw_error(ERR_FILECONTENT);
			return (FALSE);
		}
		else
		step += last;
	}
	return (TRUE);
}
