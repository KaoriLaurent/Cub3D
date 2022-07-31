/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 05:40:06 by requinch          #+#    #+#             */
/*   Updated: 2022/07/31 06:01:26 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*get_next_element(char	*raw)
{
	t_counter	index;

	index = 0;
	while (raw[index] == '\n')
		index++;
	return (&raw[index]);
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
	index = 0;
	while (raw[start + index] != '\n')
	{
		texpath[index] = raw[start + index];
		index++;
	}
	texpath[index] = NULL;
	return (texpath);
}