/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 03:24:43 by requinch          #+#    #+#             */
/*   Updated: 2022/07/09 15:56:13 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
/*
int	main(int ac, char **av)
{
	t_world	world;

	if (ac != 2)
		return (error_int_ret(ERR_ARG, 0)); //temp, do we need more than filepath as arg ?
	world.map.raw = read_file(av[1]);
	if (!world.map.raw || !parsing(av[1]))
		return (0);
	printf("OK");
	//fill in &map
	//do stuff
	return (1);
}*/

int	main()
{
	//t_vars		*vars;
	
	//vars = malloc(sizeof(t_vars));
	//window_init(vars);
	randomalgo();
	//mlx_key_hook(vars->win, wclose, &vars);
	//mlx_loop(vars->mlx);
	return (0);
}
