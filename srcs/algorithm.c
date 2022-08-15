/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:48:58 by anbourge          #+#    #+#             */
/*   Updated: 2022/08/15 17:52:34 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	get_dir(float dir, int input)
{
	if (input == 3)
	{
		dir -= 90.0f;
		if (dir < 0.0f)
			dir = 360.0f + dir;
	}
	else if (input == 2)
	{
		dir += 180.0f;
		if (dir > 360.0f)
			dir = dir - 360.0f;
	}
	else if (input == 1)
	{
		dir += 90.0f;
		if (dir > 360.0f)
			dir = dir - 360.0f;
	}
	return (degtorad(dir));
}

int	get_wall_side2(float *diff, float *tmp, int *ret)
{
	if (diff[2] < diff[3])
	{
		tmp[1] = diff[2];
		ret[1] = 3;
	}
	else
	{
		tmp[1] = diff[3];
		ret[1] = 1;
	}
	if (tmp[0] < tmp[1])
		return (ret[0]);
	return (ret[1]);
}

int	get_wall_side(t_position pos, int wall_x, int wall_y)
{
	float	diff[4];
	float	tmp[2];
	int		ret[2];

	diff[0] = pos.x - (float)wall_x;
	diff[1] = (float)(wall_x + 1) - pos.x;
	diff[2] = pos.y - (float)wall_y;
	diff[3] = (float)(wall_y + 1) - pos.y;
	if (diff[0] < diff[1])
	{
		tmp[0] = diff[0];
		ret[0] = 2;
	}
	else
	{
		tmp[0] = diff[1];
		ret[0] = 0;
	}
	return (get_wall_side2(diff, tmp, ret));
}

void	algorithm2()
{
	
}

t_rays	*algorithm(t_all *a)
{
	int			ray[2];
	t_position	p;
	t_rays		*rays;
	float		angle[2];
	float		r[2];
	float		ratio;

	rays = NULL;
	angle[0] = set_angle(a);
	angle[1] = set_angle2(a);
	while ((int)angle[0] != (int)angle[1])
	{
		ray[0] = a->world->player.pos.y;
		ray[1] = a->world->player.pos.x;
		r[0] = 0.0;
		r[1] = 0.0;
		ratio = 0.1;
		while (ratio >= 0.000001)
		{
			p = next_intersection(angle[0], a->world->player, r[0]);
			ray[0] = p.y;
			ray[1] = p.x;
			if (a->world->map.map[ray[0]][ray[1]] == 1 && ratio >= 0.000001)
			{
				ratio /= 10;
				r[0] = r[1];
			}
			r[1] = r[0];
			r[0] += ratio;
		}
		rays = get_ray(rays, p, a, ray);
		angle[0] = incr_angle(angle[0]);
	}
	return (rays);
}
