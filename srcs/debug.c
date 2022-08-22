/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 01:14:37 by requinch          #+#    #+#             */
/*   Updated: 2022/08/22 20:35:20 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_world(t_world world)
{
	printf("Debug : printing all world info\n");
	printf("Debug : printing player info\n");
	printf("Debug : player position : %f, ", world.player.pos.x);
	printf("%f\n", world.player.pos.y);
	printf("Debug : player FOV : %f \n", world.player.fov);
	printf("Debug : player direction : %f\n", world.player.dir);
	printf("Debug : printing map info\n");
	print_map_int(world.map.map);
	printf("Debug : starting position : %f, ", world.map.start_pos.x);
	printf("%f\n", world.map.start_pos.y);
	printf("Debug : north texpath : %s\n", world.map.tex_path[0]);
	printf("Debug : south texpath : %s\n", world.map.tex_path[1]);
	printf("Debug : west texpath : %s\n", world.map.tex_path[2]);
	printf("Debug : east texpath : %s\n", world.map.tex_path[3]);
	printf("Debug : ground color : %u \n", world.map.ground_clr);
	printf("Debug : ceiling color : %u \n", world.map.ceiling_clr);
}

void	print_map_char(char **map)
{
	int	pos;

	pos = 0;
	printf("Debug : Printing character map\n");
	while (map[pos])
	{
		printf("%s\n", map[pos]);
		pos++;
	}
}

void	print_map_int(int **map)
{
	t_vector	pos;

	pos.y = 0;
	printf("Debug : Printing integer map\n");
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x] > -1)
		{
			printf("%i", map[pos.y][pos.x]);
			pos.x++;
		}
		printf("-1\n");
		pos.y++;
	}
	printf("NULL\n");
}

void	step_debug_map_filler(char *raw, int index)
{
	char	tmp;

	getchar();
	printf("Debug : checking index %i\n", index);
	tmp = raw[index];
	raw[index] = 'X';
	printf("%s\n", raw);
	raw[index] = tmp;
}

void	step_debug_map_parser(char **map, t_vector pos, t_counter step)
{
	char	tmp;

	getchar();
	printf("Debug : checking pos (%i, %i). Step %i.\n", pos.x, pos.y, step);
	if (pos.x < 0 || pos.y < 0)
	{
		printf("Debug : one coordinate is negative, wtf dude");
		return ;
	}
	tmp = map[pos.y][pos.x];
	map[pos.y][pos.x] = 'X';
	print_map_char(map);
	map[pos.y][pos.x] = tmp;
}
