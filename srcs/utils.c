/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:14:06 by anbourge          #+#    #+#             */
/*   Updated: 2022/08/22 18:13:23 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_angles(t_all *a, float *f)
{
	f[0] = a->world->player.dir - (a->world->player.fov / 2.0f);
	if (f[0] < 0.0f)
		f[0] = 360.0f + f[0];
	f[1] = (a->world->player.dir + (a->world->player.fov / 2.0f));
	if (f[1] > 360.0f)
		f[1] = f[1] - 360.0f;
}

void	set_ratios(float *f)
{
	f[2] = 0.0;
	f[3] = 0.0;
	f[4] = 0.01;
}

float	incr_angle(float angle)
{
	angle += 0.10f;
	if (angle > 360.0f)
		angle = angle - 360.0f;
	return (angle);
}
