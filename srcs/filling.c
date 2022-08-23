/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 05:20:05 by requinch          #+#    #+#             */
/*   Updated: 2022/08/23 18:04:53 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	fill_player(t_vector current, t_player *player, char *c)
{
	if (c[0] == 32)
	{
		c[0] = '0';
		return ;
	}
	if (c[0] == 'N')
		player->dir = 90.0;
	else if (c[0] == 'S')
		player->dir = 270.0;
	else if (c[0] == 'W')
		player->dir = 180.0;
	else if (c[0] == 'E')
		player->dir = 0.0;
	c[0] = '0';
	player->pos.x = (float)current.x + 0.5f;
	player->pos.y = (float)current.y + 0.5f;
	player->fov = 60.0;
}

void	fill_mapmapmap(int **map, char *raw, t_player *player, int index)
{
	t_vector	current;

	current.x = -1;
	current.y = 0;
	while (raw[++index])
	{
		current.x += 1;
		if (raw[index] == 'N' || raw[index] == 'S'
			|| raw[index] == 'E' || raw[index] == 'W' || raw[index] == 32)
			fill_player(current, player, &raw[index]);
		if (raw[index] == '1' || raw[index] == '0')
			map[current.y][current.x] = raw[index] - 48;
		if (raw[index] == '\n')
		{
			if (raw[index - 1] == '\n')
				break ;
			current = osef(current, &map[current.y][current.x]);
		}
	}
	if (current.x > 0)
		map[current.y][current.x] = -1;
}

/* 
**	x and y logically inverted here, doesn't matter.
*/

int	**fill_mapmap(int **map, char *raw, t_player *player, int index)
{
	t_vector	current;
	int			*temp[1000];

	current.x = 0;
	while (raw[index])
	{
		current.y = 0;
		while (raw[index + current.y] && raw[index + current.y] != '\n')
			current.y += 1;
		if (current.y == 0)
			break ;
		temp[current.x] = ft_calloc(current.y + 1, sizeof(int));
		current.x += 1;
		if (!raw[index + current.y])
			break ;
		index += current.y + 1;
	}
	map = malloc((current.x + 1) * sizeof(int *));
	map[current.x] = NULL;
	while (--current.x > -1)
		map[current.x] = temp[current.x];
	fill_mapmapmap(map, raw, player, -1);
	return (map);
}

void	fill_map(t_map *map, t_player *player, t_counter step)
{
	map->raw = get_next_element(map->raw, step);
	if (step == 7)
		return ;
	else if (step == 6)
	{
		map->map = fill_mapmap(map->map, map->raw, player, 0);
		map->start_pos = player->pos;
	}
	else if (map->raw[0] == 'N')
		map->tex_path[0] = get_texpath(map->raw);
	else if (map->raw[0] == 'S')
		map->tex_path[1] = get_texpath(map->raw);
	else if (map->raw[0] == 'W')
		map->tex_path[2] = get_texpath(map->raw);
	else if (map->raw[0] == 'E')
		map->tex_path[3] = get_texpath(map->raw);
	else if (map->raw[0] == 'C')
		map->ceiling_clr = get_color(map->raw);
	else if (map->raw[0] == 'F')
		map->ground_clr = get_color(map->raw);
	else
		throw_error(ERR_UNDEFINED);
	fill_map(map, player, step + 1);
	return ;
}

void	fill_world(t_world *world)
{
	char	*raw_save;

	raw_save = world->map.raw;
	fill_map(&world->map, &world->player, 0);
	world->map.raw = raw_save;
}
