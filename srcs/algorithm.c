/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:48:58 by anbourge          #+#    #+#             */
/*   Updated: 2022/08/15 17:31:11 by anbourge         ###   ########.fr       */
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

t_rays	*algorithm(t_all *a)
{
	int			ray[3];
	t_position	p;
	t_rays		*rays;
	float		angle;
	float		tmp;
	float		r[2];
	float		ratio;

	rays = NULL;
	ray[2] = 0;
	angle = a->world->player.dir - (a->world->player.fov / 2.0f);
	if (angle < 0.0f)
		angle = 360.0f + angle;
	tmp = (a->world->player.dir + (a->world->player.fov / 2.0f)) + 1.0f;
	if (tmp > 360.0f)
		tmp = tmp - 360.0f;
	while ((int)angle != (int)tmp)
	{
		ray[0] = a->world->player.pos.y;
		ray[1] = a->world->player.pos.x;
		r[0] = 0.0;
		r[1] = 0.0;
		ratio = 0.1;
		while (ratio >= 0.000001)
		{
			p = next_intersection(angle, a->world->player, r[0]);
			ray[0] = p.y;
			ray[1] = p.x;
			if (worldMap[ray[0]][ray[1]] == 1 && ratio >= 0.000001)
			{
				ratio /= 10;
				r[0] = r[1];
			}
			r[1] = r[0];
			r[0] += ratio;
		}
		ray[2] = get_wall_side(p, ray[1], ray[0]);
		if (!rays)
			rays = first_ray(p, a->world->player.pos, ray);
		else
			rays = add_ray(rays, p, a->world->player.pos, ray);
		angle += 0.10f;
		if (angle > 360.0f)
		angle = angle - 360.0f;
	}
	return (rays);
}
