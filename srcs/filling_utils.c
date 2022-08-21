/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 05:40:06 by requinch          #+#    #+#             */
/*   Updated: 2022/08/21 17:54:32 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*get_next_element(char *raw, t_counter step)
{
	int	index;

	index = 0;
	if (step)
		while (raw[index] != '\n')
			index++;
	while (raw[index] == '\n')
		index++;
	return (&raw[index]);
}

int	get_color(char *raw)
{
	int	start;
	int	r;
	int	g;
	int	b;

	start = 1;
	while (raw[start] == 32)
		start++;
	r = ft_atoi(&raw[start]);
	start += 2 + ((r / 10) > 0) + ((r / 100) > 0);
	g = ft_atoi(&raw[start]);
	start += 2 + ((r / 10) > 0) + ((r / 100) > 0);
	b = ft_atoi(&raw[start]);
	return (r << 16 | g << 8 | b);
}

char	*get_texpath(char *raw)
{
	int		start;
	int		index;
	char	*texpath;

	start = 2;
	index = 0;
	while (raw[start] == 32)
		start++;
	while (raw[start + index] != '\n')
		index++;
	texpath = malloc(sizeof(char) * (index + 1));
	if (!texpath)
		return (throw_error(ERR_MALLOC));
	index = 0;
	while (raw[start + index] != '\n')
	{
		texpath[index] = raw[start + index];
		index++;
	}
	texpath[index] = 0;
	return (texpath);
}

t_vector	osef(t_vector current, int *steak)
{
	if (current.x != 0)
	{
		*steak = -1;
		current.y += 1;
		current.x = -1;
	}
	return (current);
}
