/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:11:01 by anbourge          #+#    #+#             */
/*   Updated: 2022/07/22 18:50:13 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	my_key_hook(int keycode, t_all *all)
{
	if (keycode == 53)
	{
		//mlx_destroy_image(vars->mlx, &vars->img);
		mlx_destroy_window(all->vars->mlx, all->vars->win);
		exit(0);
	}
	else
		player_movements(keycode, all);
	//printf("KEYCODE IS : %i\n", keycode);
	return (0);
}

void	player_movements(int keycode , t_all *a)
{
	if (keycode == 13)
		a->player->pos.y -= 0.3;
	if (keycode == 0)
		a->player->pos.x -= 0.3;
	if (keycode == 1)
		a->player->pos.y += 0.3;
	if (keycode == 2)
		a->player->pos.x += 0.3;
}

int	render_next_frame(void *s)
{
	t_rays		*r;
	t_vars		*vars;
	t_player	*p;
	t_all		*a;
	
	a = s;
	vars = a->vars;
	p = a->player;
	/*if (p->dir < 360.0)
		p->dir += 0.1;
	else
		p->dir = 0.0;*/
	r = randomalgo(p);
	graphics(r, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}
