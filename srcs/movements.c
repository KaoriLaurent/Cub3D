/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:11:01 by anbourge          #+#    #+#             */
/*   Updated: 2022/08/02 17:29:25 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	my_key_hook(int keycode, t_all *all)
{
	if (keycode == 53)
	{
		mlx_destroy_window(all->vars->mlx, all->vars->win);
		exit(0);
	}
	else
		player_movements(keycode, all);
	return (0);
}

int	is_wall(float x, float y)
{
	int	pos[2];

	pos[0] = (int)y;
	pos[1] = (int)x;
	if (worldMap[pos[0]][pos[1]] != 0)
		return (0);
	pos[0] = (int)roundf(y + 0.3);
	pos[1] = (int)roundf(x + 0.3);
	if (worldMap[pos[0]][pos[1]] != 0)
		return (0);
	pos[0] = (int)roundf(y - 0.3);
	pos[1] = (int)roundf(x - 0.3);
	if (worldMap[pos[0]][pos[1]] != 0)
		return (0);
	return (1);
}

void	player_movements(int keycode, t_all *a)
{
	float	tmp[2];

	tmp[0] = a->player->pos.y;
	tmp[1] = a->player->pos.x;
	if (keycode == 13)
	{
		a->player->pos.y -= (sin(degtorad(a->player->dir)) * 0.5);
		a->player->pos.x += (cos(degtorad(a->player->dir)) * 0.5);
	}
	if (keycode == 0)
	{
		a->player->pos.y -= (sin(get_dir(a->player->dir, 1)) * 0.5);
		a->player->pos.x += (cos(get_dir(a->player->dir, 1)) * 0.5);
	}
	if (keycode == 1)
	{
		a->player->pos.y -= (sin(get_dir(a->player->dir, 2)) * 0.5);
		a->player->pos.x += (cos(get_dir(a->player->dir, 2)) * 0.5);
	}
	if (keycode == 2)
	{
		a->player->pos.y -= (sin(get_dir(a->player->dir, 3)) * 0.5);
		a->player->pos.x += (cos(get_dir(a->player->dir, 3)) * 0.5);
	}
	if (keycode == 123)
	{
		if (a->player->dir + 5.0 <= 360.0)
			a->player->dir += 5.0;
		else
			a->player->dir = a->player->dir + 5.0 - 360.0;
	}
	if (keycode == 124)
	{
		if (a->player->dir - 5.0 >= 0)
			a->player->dir -= 5.0;
		else
			a->player->dir = 360.0 + (a->player->dir - 5.0);
	}
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
	r = randomalgo(p);
	graphics(r, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}
