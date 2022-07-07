/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 03:24:43 by requinch          #+#    #+#             */
/*   Updated: 2022/07/07 03:24:43 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_map_info	map;

	if (ac != 2)
		return (0); //temp, do we need more than filepath as arg ?
	map.raw = read_file(av[1]);
	if (!map.raw || !parsing(map.raw))
		return (0);
	//fill in &map
	//do stuff
	return (1);
}
