/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:11:01 by anbourge          #+#    #+#             */
/*   Updated: 2022/08/17 01:17:49 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	my_key_hook(int keycode, t_all *all)
{
	if (keycode == 53)
		my_exit_hook(all);
	else if (check_player_movement(keycode, all->world))
		player_movements(keycode, &all->world->player);
	return (0);
}

int	render_next_frame(t_all *a)
{
	t_rays	*rays;

	rays = NULL;
	a->r = algorithm(a, rays);
	graphics(a);
	mlx_put_image_to_window(a->vars->mlx, a->vars->win, a->vars->img.img, 0, 0);
	return (0);
}

int	check_player_movement(int keycode, t_world *world)
{
	t_player	p;

	if (keycode == 123 || keycode == 124)
		return (1);
	p.pos.x = world->player.pos.x;
	p.pos.y = world->player.pos.y;
	p.dir = world->player.dir;
	player_movements(keycode, &p);
	if (world->map.map[(int)p.pos.y][(int)p.pos.x] == 1)
		return (0);
	return (1);
}

void	player_camera_movements(int keycode, t_player *player)
{
	if (keycode == 123)
	{
		if (player->dir + 6.0f <= 360.0f)
			player->dir += 6.0f;
		else
			player->dir = player->dir + 6.0f - 360.0f;
	}
	if (keycode == 124)
	{
		if (player->dir - 6.0f >= 0.0f)
			player->dir -= 6.0f;
		else
			player->dir = 360.0f + (player->dir - 6.0f);
	}
}

void	player_movements(int keycode, t_player *player)
{
	if (keycode == 13)
	{
		player->pos.y -= (sin(degtorad(player->dir)) * 0.42f);
		player->pos.x += (cos(degtorad(player->dir)) * 0.42f);
	}
	if (keycode == 0)
	{
		player->pos.y -= (sin(get_dir(player->dir, 1)) * 0.42f);
		player->pos.x += (cos(get_dir(player->dir, 1)) * 0.42f);
	}
	if (keycode == 1)
	{
		player->pos.y -= (sin(get_dir(player->dir, 2)) * 0.42f);
		player->pos.x += (cos(get_dir(player->dir, 2)) * 0.42f);
	}
	if (keycode == 2)
	{
		player->pos.y -= (sin(get_dir(player->dir, 3)) * 0.42f);
		player->pos.x += (cos(get_dir(player->dir, 3)) * 0.42f);
	}
	player_camera_movements(keycode, player);
}
