/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:48:58 by anbourge          #+#    #+#             */
/*   Updated: 2022/08/23 18:24:18 by requinch         ###   ########.fr       */
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

int	map_check_pos(int **map, int *ray, float f)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (ray[0] > (i - 1) || ray[0] < 1)
		return (1);
	i = 0;
	while (map[ray[0]][i] != -1)
		i++;
	if (ray[1] > (i - 1) || ray[1] < 1)
		return (1);
	if (map[ray[0]][ray[1]] == 1 && f >= 0.000001)
		return (1);
	return (0);
}

/*
**	f[0] = angle
**	f[1] = angle max
**	f[2] = actual ratio
**	f[3] = last ratio
**	f[4] = ratio multiplicator
*/

void	algorithm(t_all *a, int i)
{
	int			ray[2];
	t_position	p;
	float		f[5];

	set_angles(a, f);
	while (i < 599)
	{
		set_ratios(f);
		while (f[4] >= 0.000001)
		{
			p = next_intersection(f[0], a->world->player, f[2]);
			ray[0] = p.y;
			ray[1] = p.x;
			if (map_check_pos(a->world->map.map, ray, f[4]))
			{
				f[4] /= 10;
				f[2] = f[3];
			}
			f[3] = f[2];
			f[2] += f[4];
		}
		get_ray(++i, p, a, ray);
		f[0] = incr_angle(f[0]);
	}
}
