/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:31:55 by requinch          #+#    #+#             */
/*   Updated: 2022/07/09 04:39:16 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	free_map(char **map, int ret)
{
	unsigned int	x;

	x = 0;
	while (map[x])
	{
		free(map[x]);
		x += 1;
	}
	free(map);
	return (ret);
}