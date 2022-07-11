/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:48:58 by anbourge          #+#    #+#             */
/*   Updated: 2022/07/11 16:32:50 by anbourge         ###   ########.fr       */
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

t_position	next_intersection(short angle, t_player p, short r)
{
	t_position	pos;
	
	pos.x = p.pos.x + (cos(degtorad(angle)) * r);
	pos.y = p.pos.y - (sin(degtorad(angle)) * r);
	return (pos);
}

t_walls	*first_wall(t_position pos)
{
	t_walls	*wall;
	
	wall = malloc(sizeof(t_walls));
	if (!wall)
		return (throw_error(10));
	wall->x = pos.x;
	wall->y = pos.y;
	wall->next = NULL;
	return (wall);
}

t_walls	*add_wall(t_walls *w, t_position pos)
{
	t_walls	*new;
	t_walls	*tmp;

	tmp = w;
	while (tmp->next)
	{
		if (w->x == pos.x && w->y == pos.y)
			return (w);
		tmp = tmp->next;
	}
	new = malloc(sizeof(t_walls));
	if (!new)
		return (throw_error(10));
	new->x = pos.x;
	new->y = pos.y;
	new->next = NULL;
	tmp->next = new;
	return (w);
}

void	randomalgo()
{
	int		ray[2];
	t_player	player;
	t_position	p;
	//t_walls		*walls;
	short	angle;
	int		i;
	
	player.pos.x = 19;
	player.pos.y = 16;
	player.fov = 60;
	player.dir = 270;
	angle = player.dir - (player.fov / 2);
	while (angle != (player.dir + (player.fov / 2)) + 1)
	{
		i = 1;
		ray[0] = player.pos.y;
		ray[1] = player.pos.x;
		while (worldMap[ray[0]][ray[1]] == 0)
		{
			p = next_intersection(angle, player, i);
			ray[0] = p.y;
			ray[1] = p.x;
			i++;
		}
		/*if (!walls)
			walls = first_wall(p);
		else
			walls = add_wall(walls, p);*/
		worldMap[ray[0]][ray[1]] = 3;
		printf("first wall encountered with angle %i : (%i, %i)\n", angle, ray[0], ray[1]);
		angle++;
	}
	worldMap[16][19] = 4;
	i = 0;
	int	j = 0;
	while (i < 24)
	{
		j = 0;
		while (j < 24)
		{
			printf("%i ", worldMap[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}