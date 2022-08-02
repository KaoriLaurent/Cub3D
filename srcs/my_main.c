/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:08:23 by anbourge          #+#    #+#             */
/*   Updated: 2022/08/02 18:18:31 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main()
{
	t_vars		*vars;
	t_all		*a;
	t_player	*p;
	
	vars = malloc(sizeof(t_vars));
	p = malloc(sizeof(t_player));
	a = malloc(sizeof(t_all));
	window_init(vars);
	p->pos.x = 16.000;
	p->pos.y = 19.000;
	p->dir = 90.000;
	p->fov = 60.000;
	vars->p = p;
	a->vars = vars;
	a->player = p;
	mlx_loop_hook(vars->mlx, render_next_frame, a);
	mlx_hook(vars->win, 2, 0, my_key_hook, a);
	mlx_loop(vars->mlx);
}
