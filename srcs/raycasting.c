/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:44:34 by anbourge          #+#    #+#             */
/*   Updated: 2022/08/22 20:34:32 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_position	next_intersection(float angle, t_player p, float r)
{
	t_position	pos;

	pos.x = p.pos.x + (cos(degtorad(angle)) * r);
	pos.y = p.pos.y - (sin(degtorad(angle)) * r);
	return (pos);
}

void	get_ray(int i, t_position p, t_all *a, int *ray)
{
	if (i > 0)
		add_ray(a, p, a->world->player.pos, ray);
	else
		first_ray(a, p, a->world->player.pos, ray);
}

void	first_ray(t_all *all, t_position pos, t_position player_pos, int *wall)
{
	all->r->x = pos.x;
	all->r->y = pos.y;
	all->r->dist = sqrtf(powf(pos.x - player_pos.x, 2.0)
			+ powf(pos.y - player_pos.y, 2.0));
	all->r->wall_x = wall[1];
	all->r->wall_y = wall[0];
	all->r->side = get_wall_side(pos, wall[1], wall[0]);
	all->r->next = NULL;
}

void	add_ray(t_all *all, t_position pos, t_position player_pos, int *wall)
{
	t_rays	*new;
	t_rays	*tmp;

	tmp = all->r;
	while (tmp->next)
		tmp = tmp->next;
	new = malloc(sizeof(t_rays));
	if (!new)
		return ;
	new->x = pos.x;
	new->y = pos.y;
	new->dist = sqrtf(powf(pos.x - player_pos.x, 2.0)
			+ powf(pos.y - player_pos.y, 2.0));
	new->wall_x = wall[1];
	new->wall_y = wall[0];
	new->side = get_wall_side(pos, wall[1], wall[0]);
	new->next = NULL;
	tmp->next = new;
}

float	set_r(float angle, t_position pos, int i, int a)
{
	float	r1;

	(void)angle;
	if (a == 0)
	{
		if (roundf(pos.x) >= pos.x)
			r1 = roundf(pos.x) - pos.x;
		else
			r1 = pos.x - roundf(pos.x);
	}
	else
	{
		if (roundf(pos.y) >= pos.y)
			r1 = roundf(pos.y) - pos.y;
		else
			r1 = pos.y - roundf(pos.y);
	}
	r1 += i;
	return (r1);
}
