/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:14:06 by anbourge          #+#    #+#             */
/*   Updated: 2022/07/31 04:03:30 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	isInteger(float f)
{
	int i = (int)f;
	if (f == i)
		return (1);
	return (0);
}

void	print_map_char(char **map)
{
	int	pos;

	pos = 0;
	printf("Debug : Printing map\n");
	while (map[pos])
	{
		printf("%s\n", map[pos]);
		pos++;
	}
}

void	step_debug_map_parser(char **map, t_vector pos, t_counter step)
{
	char	tmp;

	getchar();
	system("clear");
	printf("Debug : checking pos (%i, %i). Step %i.\n", pos.x, pos.y, step);
	tmp = map[pos.y][pos.x];
	map[pos.y][pos.x] = 'X';
	print_map_char(map);
	map[pos.y][pos.x] = tmp;
}