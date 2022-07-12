/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:44:34 by anbourge          #+#    #+#             */
/*   Updated: 2022/07/12 18:00:23 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_position	next_intersection(float angle, t_player p, int r)
{
	t_position	pos;
	
	pos.x = p.pos.x + (cos(degtorad(angle)) * r);
	pos.y = p.pos.y - (sin(degtorad(angle)) * r);
	return (pos);
}

t_rays	*first_ray(t_position pos, t_position player_pos, int *wall)
{
	t_rays	*r;
	
	r = malloc(sizeof(t_rays));
	if (!r)
		return (throw_error(10));
	
	r->x = pos.x;
	r->y = pos.y;
	r->dist = sqrtf(powf(pos.x - player_pos.x, 2.0)
		+ powf(pos.y - player_pos.y, 2.0));
	r->wall_x = wall[1];
	r->wall_y = wall[0];
	r->next = NULL;
	return (r);
}

t_rays	*add_ray(t_rays *r, t_position pos, t_position player_pos, int *wall)
{
	t_rays	*new;
	t_rays	*tmp;

	tmp = r;
	while (tmp->next)
		tmp = tmp->next;
	new = malloc(sizeof(t_rays));
	if (!new)
		return (throw_error(10));
	new->x = pos.x;
	new->y = pos.y;
	new->dist = sqrtf(powf(pos.x - player_pos.x, 2.0)
		+ powf(pos.y - player_pos.y, 2.0));
	printf("DISTANCE = %f\n", powf(pos.x - player_pos.x, 2.0));
	new->wall_x = wall[1];
	new->wall_y = wall[0];
	new->next = NULL;
	tmp->next = new;
	return (r);
}
