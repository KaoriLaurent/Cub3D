/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 03:24:43 by requinch          #+#    #+#             */
/*   Updated: 2022/08/01 04:57:14 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
**	IMPORTANT ANNOUNCEMENT
**
**	MATHMECH CIRCULAR
**
**	That was all thanks for your attention
*/

int	main(int ac, char **av)
{
	t_world	world;

	if (ac != 2)
		return (error_int_ret(ERR_ARG, 0));
	if (!parsing(av[1]))
		return (1);
	world.map.raw = read_file(av[1]);
	if (!world.map.raw)
		return (free_return(world.map.raw, 1));
	fill_world(&world);
	print_world(world);
	return (free_world(&world));
}
