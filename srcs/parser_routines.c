/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:50:14 by requinch          #+#    #+#             */
/*   Updated: 2022/07/07 17:50:14 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

short	parse_texture(char *line, t_counter step)
{
	t_counter	index;

	index = 2;
	if (!(*line))
		return (0);
	if (line[0] && line[1] && ((step == 0 && line[0] == 'N' && line[1] == 'O')
		|| (step == 1 && line[0] == 'S' && line[1] == 'O')
		|| (step == 2 && line[0] == 'W' && line[1] == 'E')
		|| (step == 3 && line[0] == 'E' && line[1] == 'A')))
	{
		while (line[index] == ' ')
			index++;
		index = open(&line[index], O_RDONLY);
		if (index < 0)
			return (2);
		close(index);
		return (1);
	}
	return (2);
}

short	parse_color(char *line, t_counter step)
{
	t_counter	index;
	t_counter	c_nbr;

	index = 1;
	c_nbr = 1;
	if (!(*line))
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
			index += 1 + ((ft_atoi(&line[index] / 10) > 0)
				+ ((ft_atoi(&line[index] / 100) > 0);
			c_nbr += 1;
		}
		return (1);
	}
	return (2);
}

short	parse_map(char *line)
{

}

short	parse_rest(char *line)
{

}
