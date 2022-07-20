/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:48:58 by anbourge          #+#    #+#             */
/*   Updated: 2022/07/20 16:54:22 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int worldMap[24][24]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

t_rays	*randomalgo()
{
	int		ray[3];
	t_player	player;
	t_position	p;
	t_rays	*rays;
	float	angle;
	float	r;
	
	rays = NULL;
	player.pos.x = 19;
	player.pos.y = 16;
	player.fov = 60.000;
	player.dir = 210.000;
	angle = player.dir - (player.fov / 2.000);
	while ((int)angle != (int)(player.dir + (player.fov / 2.000)) + 1.000)
	{
		ray[0] = player.pos.y;
		ray[1] = player.pos.x;
		r = 0;
		while (worldMap[ray[0]][ray[1]] == 0)
		{
			p = next_intersection(angle, player, r);
			//printf("Intersection (%f,%f)\n", p.y, p.x);
			ray[0] = p.y;
			ray[1] = p.x;
			r += 0.1;
		}
		//printf("Intersection (%i,%i) / (%f,%f)\n", ray[0], ray[1], p.y, p.x);
		//printf("deg = %f / rad = %f\n", angle, degtorad(angle));
		if (!rays)
			rays = first_ray(p, player.pos, ray);
		else
			rays = add_ray(rays, p, player.pos, ray);
		worldMap[ray[0]][ray[1]] = 3;
		//printf("first wall encountered with angle %f : (%i, %i)\n", angle, ray[0], ray[1]);
		angle += 0.10;
	}
	worldMap[16][19] = 4;
	int k = 0;
	int	j = 0;
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
	return (rays);
}