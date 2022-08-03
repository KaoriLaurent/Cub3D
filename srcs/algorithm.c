/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:48:58 by anbourge          #+#    #+#             */
/*   Updated: 2022/08/04 00:37:52 by anbourge         ###   ########.fr       */
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

float	r_incr(t_position p, float angle)
{
	float r1;
	float r2;
	
	r1 = (1.0 - fmodf(p.x, 1.0)) / cos(degtorad(angle));
	r2 = (1.0 - fmodf(p.y, 1.0)) / sin(degtorad(angle));
	//if (angle == 90.000 || angle == 270.000)
	//	return (r2);
	//printf("r1 = %f / r2 = %f for pos (%f,%f) and angle %f\n", r1, r2, p.x, p.y, angle);
	if (r1 <= r2 && (int)r1 != 0)
		return (r1);
	else if (r2 < r1 && (int)r2 != 0)
		return (r2);
	else
	{
		//printf("caca\n");
		return (0.01);
	}
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
	//printf("diff[0] = %f / diff[1] = %f / diff[2] = %f / diff[3] = %f\n", diff[0], diff[1], diff[2], diff[3]);
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
		return(ret[0]);
	return(ret[1]);
}

void	print_map(void)
{
	int k = 0;
	int	j = 0;
	printf("MAP :\n");
	while (k < 24)
	{
		j = 0;
		while (j < 24)
		{
			printf("%i ", worldMap[k][j]);
			j++;
		}
		printf("\n");
		k++;
	}
	printf("\n");
}

t_rays	*randomalgo(t_player *pp)
{
	int		ray[3];
	t_player	player;
	t_position	p;
	t_rays	*rays;
	float	angle;
	float	tmp;
	float	r[2];
	float	ratio;
	
	rays = NULL;
	ray[2] = 0;
	player.pos.x = pp->pos.x;
	player.pos.y = pp->pos.y;
	player.fov = pp->fov;
	player.dir = pp->dir;
	angle = player.dir - (player.fov / 2.0f);
	if (angle < 0.0f)
		angle = 360.0f + angle;
	tmp = (player.dir + (player.fov / 2.0f)) + 1.0f;
	if (tmp > 360.0f)
		tmp = tmp - 360.0f;
	//printf("angle is %f\ntmp is %f\n", angle, tmp);
	while ((int)angle != (int)tmp)
	{
		ray[0] = player.pos.y;
		ray[1] = player.pos.x;
		r[0] = 0.0;
		r[1] = 0.0;
		ratio = 0.1;
		while (ratio >= 0.000001)
		{
			p = next_intersection(angle, player, r[0]);
			//printf("Intersection (%f,%f) with angle %f\n", p.y, p.x, angle);
			ray[0] = p.y;
			ray[1] = p.x;
			if (worldMap[ray[0]][ray[1]] == 1 && ratio >= 0.000001)
			{
				//printf("Intersection (%f,%f)\nAngle %f\n", p.y, p.x, angle);
				ratio /= 10;
				r[0] = r[1];
			}
			r[1] = r[0];
			r[0] += ratio;
			//r += r_incr(p, angle);
			//printf("r = %f\n", r_incr(p, angle));
		}
		//printf("Intersection (%f,%f) with angle %f\n", p.y, p.x, angle);
		//worldMap[ray[0]][ray[1]] = 3;
		//print_map();
		ray[2] = get_wall_side(p, ray[1], ray[0]);
		//printf("Angle = %f\nIntersection (%f,%f) for wall (%i,%i)\nside = %i\n", angle, p.x, p.y, ray[1], ray[0], ray[2]);
		//printf("deg = %f / rad = %f\n", angle, degtorad(angle));
		if (!rays)
			rays = first_ray(p, player.pos, ray);
		else
			rays = add_ray(rays, p, player.pos, ray);
		//printf("first wall encountered with angle %f : (%i, %i)\n", angle, ray[0], ray[1]);
		angle += 0.10f;
		if (angle > 360.0f)
		angle = angle - 360.0f;
	}
	//print_map();
	return (rays);
}