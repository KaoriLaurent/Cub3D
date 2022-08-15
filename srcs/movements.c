/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:11:01 by anbourge          #+#    #+#             */
/*   Updated: 2022/08/15 18:27:05 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	my_key_hook(int keycode, t_all *all)
{
	if (keycode == 53)
		my_exit_hook(all);
	else
		player_movements(keycode, &all->world->player);
	return (0);
}

int	render_next_frame(t_all *a)
{
	a->r = algorithm(a);
	graphics(a);
	mlx_put_image_to_window(a->vars->mlx, a->vars->win, a->vars->img.img, 0, 0);
	return (0);
}

void	player_camera_movements(int keycode, t_player *player)
{
	if (keycode == 123)
	{
		if (player->dir + 5.0 <= 360.0)
			player->dir += 5.0;
		else
			player->dir = player->dir + 5.0 - 360.0;
	}
	if (keycode == 124)
	{
		if (player->dir - 5.0 >= 0)
			player->dir -= 5.0;
		else
			player->dir = 360.0 + (player->dir - 5.0);
	}
}

void	player_movements(int keycode, t_player *player)
{
	if (keycode == 13)
	{
		player->pos.y -= (sin(degtorad(player->dir)) * 0.5);
		player->pos.x += (cos(degtorad(player->dir)) * 0.5);
	}
	if (keycode == 0)
	{
		player->pos.y -= (sin(get_dir(player->dir, 1)) * 0.5);
		player->pos.x += (cos(get_dir(player->dir, 1)) * 0.5);
	}
	if (keycode == 1)
	{
		player->pos.y -= (sin(get_dir(player->dir, 2)) * 0.5);
		player->pos.x += (cos(get_dir(player->dir, 2)) * 0.5);
	}
	if (keycode == 2)
	{
		player->pos.y -= (sin(get_dir(player->dir, 3)) * 0.5);
		player->pos.x += (cos(get_dir(player->dir, 3)) * 0.5);
	}
	player_camera_movements(keycode, player);
}
