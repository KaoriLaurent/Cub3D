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
	t_world	world;

	if (ac != 2)
		return (throw_error(ERR_MANY_ARG)); //temp, do we need more than filepath as arg ?
	world.map.raw = read_file(av[1]);
	if (!world.map.raw || !parsing(av[1]))
		return (0);
	//fill in &map
	//do stuff
	return (1);
}
