/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 03:24:43 by requinch          #+#    #+#             */
/*   Updated: 2022/08/04 01:33:42 by requinch         ###   ########.fr       */
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
	window_init(a->vars);
	a->vars->p = &world.player;
	a->player = &world.player;
	mlx_loop_hook(a->vars->mlx, render_next_frame, a);
	mlx_hook(a->vars->win, 2, 0, my_key_hook, a);
	mlx_loop(a->vars->mlx);
	free(a->vars);
	free(a);
	return (free_world(&world));
}
