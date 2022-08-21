/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 03:24:43 by requinch          #+#    #+#             */
/*   Updated: 2022/08/21 17:35:27 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_world	world;
	t_all	*a;

	a = malloc(sizeof(t_all));
	a->vars = malloc(sizeof(t_vars));
	if (ac != 2)
		return (error_int_ret(ERR_ARG, 0));
	if (!parsing(av[1]))
		return (1);
	world.map.raw = read_file(av[1]);
	if (!world.map.raw)
		return (free_return(world.map.raw, 1));
	fill_world(&world);
	a->world = &world;
	window_init(a);
	mlx_hook(a->vars->win, 17, 0, my_exit_hook, a);
	mlx_hook(a->vars->win, 2, 0, my_key_hook, a);
	mlx_loop_hook(a->vars->mlx, render_next_frame, a);
	mlx_loop(a->vars->mlx);
}
