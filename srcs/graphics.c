/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:19:59 by anbourge          #+#    #+#             */
/*   Updated: 2022/07/20 16:52:25 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	graphics(t_rays *r, t_vars *vars)
{
	int	i;
	int	j;
	int	k;
	int	l;
	float	lh;
	int	start;
	int	end;
	int	color[2];
	
	i = 1;
	l = 1280;
	color[0] = 0x00FF0000;
	color[1] = 0x000700A3;
	while (r)
	{
		lh = (2.0 * 720.0) / r->dist;
		start = (-lh / 2) + (720 / 2);
		if (start < 0)
			start = 0;
		end = (lh / 2) + (720 / 2);
		if (end >= 720)
			end = 719;
		j = -1;
		//printf("Distance ray (%f,%f) = %f\n", r->x, r->y, r->dist);
		if (i % 6 == 0)
		{
			while (++j < 2)
			{
				k = start - 1;
				while (k < end)
				{
					if (r->wall_x == 23 || r->wall_y == 23 || r->wall_x == 0 || r->wall_y == 0)
						my_mlx_pixel_put(&vars->img, l, ++k, color[0]);
					else
						my_mlx_pixel_put(&vars->img, l, ++k, color[1]);
				}
				l--;
			}
		}
		else
		{
			while (++j < 3)
			{
				k = start - 1;
				while (k < end)
				{
					if (r->wall_x == 23 || r->wall_y == 23 || r->wall_x == 0 || r->wall_y == 0)
						my_mlx_pixel_put(&vars->img, l, ++k, color[0]);
					else
						my_mlx_pixel_put(&vars->img, l, ++k, color[1]);
				}
				l--;
			}
		}
		i++;
		r = r->next;
	}
}