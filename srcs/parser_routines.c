/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:50:14 by requinch          #+#    #+#             */
/*   Updated: 2022/08/23 16:37:06 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

short	parse_texture(char *line, t_counter step)
{
	t_counter	index;
	int			fd;

	index = 2;
	if (line[0] && line[1] && ((step == 0 && line[0] == 'N' && line[1] == 'O')
			|| (step == 1 && line[0] == 'S' && line[1] == 'O')
			|| (step == 2 && line[0] == 'W' && line[1] == 'E')
			|| (step == 3 && line[0] == 'E' && line[1] == 'A')))
	{
		while (line[index] == ' ')
			index++;
		if (!check_fileformat(&line[index], ".xpm"))
			return (error_int_ret(ERR_FILEFORMAT, 2));
		fd = open(&line[index], O_RDONLY);
		if (fd < 0)
			return (2);
		close(fd);
		return (1);
	}
	return (2);
}

short	parse_color(char *line, t_counter step)
{
	t_counter	index[2];

	index[0] = 1;
	index[1] = 1;
	if (line && !line[0])
		return (0);
	if (line[0] && ((step == 4 && line[0] == 'F')
			|| (step == 5 && line[0] == 'C')))
	{
		while (line[index[0]] == ' ')
			index[0]++;
		if (!is_num_or_comma(&line[index[0]], 0, 1))
			return (2);
		while (index[1] < 4)
		{
			if (ft_atoi(&line[index[0]]) < 0 || ft_atoi(&line[index[0]]) > 255)
				return (2);
			index[0] += numlen(ft_atoi(&line[index[0]]));
			index[1] += 1;
		}
		return (1);
	}
	return (2);
}

short	parse_upper(char *line)
{
	static t_boolean	checklist[6] = {FALSE};
	short				step;

	if (line && !line[0])
		return (0);
	else
	{
		step = (-1
				+ 1 * (line[0] == 'N')
				+ 2 * (line[0] == 'S')
				+ 3 * (line[0] == 'W')
				+ 4 * (line[0] == 'E')
				+ 5 * (line[0] == 'F')
				+ 6 * (line[0] == 'C'));
		if (step == -1 || checklist[step] == TRUE)
			return (2);
		checklist[step] = TRUE;
		if (step < 4)
			return (parse_texture(line, step));
		else
			return (parse_color(line, step));
	}
}

short	parse_map(char *line, int fd, int gnl_ret)
{
	char			**map;
	t_resolution	total;

	map = calloc(1000, sizeof(char *));
	total.height = 0;
	if (line && !line[0])
		return (free_return(map, 0 + 5 * (gnl_ret == 0)));
	gnl_ret = 1;
	while (line && line[0])
	{
		map[total.height] = ft_strdup(line);
		free(line);
		gnl_ret = get_next_line(fd, &line);
		if (gnl_ret == -1)
			return (error_int_ret(ERR_GNL, 3));
		total.height += 1;
	}
	free(line);
	map = mapcpy(map, total.height);
	return (check_the_map(map, total.height) + 10 * (gnl_ret == 0));
}

short	parse_rest(char *line, short gnl_ret)
{
	if (line && !line[0])
		return ((gnl_ret == 0));
	else
		return (2);
}
