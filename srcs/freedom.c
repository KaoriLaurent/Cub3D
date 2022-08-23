/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:31:55 by requinch          #+#    #+#             */
/*   Updated: 2022/08/23 04:23:30 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	free_world(t_world	*world)
{
	t_vector	current;

	current.y = 0;
	free(world->map.raw);
	free(world->map.tex_path[0]);
	free(world->map.tex_path[1]);
	free(world->map.tex_path[2]);
	free(world->map.tex_path[3]);
	while (world->map.map[current.y])
	{
		free(world->map.map[current.y]);
		current.y++;
	}
	free(world->map.map);
	return (0);
}

int	free_text(char **text, int ret)
{
	unsigned int	x;

	x = 0;
	while (text[x])
	{
		free(text[x]);
		x += 1;
	}
	free(text);
	return (ret);
}

int	free_return(void *ptdr, int ret)
{
	free (ptdr);
	return (ret);
}

void	freefree(void *uno, void *dos)
{
	free(uno);
	free(dos);
}

int	freefree_ret(void *uno, void *dos, int ret)
{
	free(uno);
	free(dos);
	return (ret);
}
