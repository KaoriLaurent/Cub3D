/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:50:14 by requinch          #+#    #+#             */
/*   Updated: 2022/07/31 04:16:47 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

short	parse_texture(char *line, t_counter step) //NOT GOOD : ANY ORDER POSSIBLE
{
	t_counter	index;
	int			fd;

	index = 2;
	if (line && !line[0])
		return (0);
	if (line[0] && line[1] && ((step == 0 && line[0] == 'N' && line[1] == 'O')
		|| (step == 1 && line[0] == 'S' && line[1] == 'O')
		|| (step == 2 && line[0] == 'W' && line[1] == 'E')
		|| (step == 3 && line[0] == 'E' && line[1] == 'A')))
	{
		while (line[index] == ' ')
			index++;
		fd = open(&line[index], O_RDONLY);
		if (fd < 0)
			return (2);
		close(fd);
		return (1);
	}
	return (2);
}

short	parse_color(char *line, t_counter step) //NOT GOOD : ANY ORDER POSSIBLE
{
	t_counter	index;
	t_counter	c_nbr;

	index = 1;
	c_nbr = 1;
	if (line && !line[0])
		return (0);
	if (line[0] && ((step == 4 && line[0] == 'F')
		|| (step == 5 && line[0] == 'C')))
	{
		while (line[index] == ' ')
			index++;
		while (c_nbr < 4)
		{
			if (ft_atoi(&line[index]) < 0 || ft_atoi(&line[index]) > 255)
				return (2);
			index += 2 + ((ft_atoi(&line[index]) / 10) > 0)
				+ ((ft_atoi(&line[index]) / 100) > 0);
			c_nbr += 1;
		}
		return (1);
	}
	return (2);
}

short	parse_map(char *line, int fd)
{
	char	**map;
	t_resolution	total;
	int	gnl_ret;

	map = calloc(1000, sizeof(char *));
	total.height = 0;
	gnl_ret = 1;
	if (line && !line[0])
		return (free_return(map, 0));
	while (line && line[0]) //ADD CONDITION ON GNL RET ?
	{
		map[total.height] = ft_strdup(line);
		free(line);
		gnl_ret = get_next_line(fd, &line);
		if (gnl_ret == -1)
			return (error_int_free(ERR_GNL, 3, line));
		total.height += 1;
	}
	free(line);
	return (check_the_map(map) + 10 * (gnl_ret == 0));
}

short	parse_rest(char *line, short gnl_ret)
{
	if (line && !line[0])
		return ((gnl_ret == 0));
	else
		return (2);
}
