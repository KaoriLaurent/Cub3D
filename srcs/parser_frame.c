/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:54:00 by requinch          #+#    #+#             */
/*   Updated: 2022/07/30 00:39:43 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
**	Return	:	0 when skip line
**				1 when proper element parsed
**				2 when invalid
**				3 when GNL dieded
**				+10 when EOF reached
*/

unsigned short	parse_next_line(int fd, t_counter step)
{
	char	*line;
	short	gnl_ret;
	short	parse_retval;

	gnl_ret = get_next_line(fd, &line);
	if (gnl_ret == -1)
	{
		throw_error(ERR_GNL);
		return (3);
	}
	if (step < 4)
		parse_retval = parse_texture(line, step);
	else if (step < 6)
		parse_retval = parse_color(line, step);
	else if (step == 6)
		parse_retval = parse_map(line, fd);
	else if (step == 7 && gnl_ret != 0)
		parse_retval = parse_rest(line, gnl_ret);
	if (step != 6 || (step == 6 && parse_retval == 0))
		free(line);
	if (gnl_ret == 0)
		return (10 + parse_retval);
	else
		return(parse_retval);
}

/*
**	Step	:		0 - 3	:	paths to NSEW textures
**					4 - 5	:	RGB colors of floor and ceiling
**					6		:	map
**					7		:	check no bullshit after map
*/

t_boolean	parsing(char *filepath)
{
	t_counter	step;
	short	last;
	int	fd;

	step = 0;
	fd = open(filepath, O_RDONLY);
	last = 1;
	if (fd < 0)
		return (error_int_ret(ERR_OPEN, 0));
	while (step < 8 && !(last / 10))
	{
		last = parse_next_line(fd, step);
		printf("Debug : parse_next_line returned %i for step %i\n", last, step);
		if ((last % 10 == 2) || (last / 10 && step < 6) || last == 3)
		{
			close (fd);
			if (last != 3)
				throw_error(ERR_FILECONTENT);
			return (FALSE);
		}
		step += last % 10;
	}
	close(fd);
	return (TRUE);
}
