/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:14:06 by anbourge          #+#    #+#             */
/*   Updated: 2022/08/15 18:25:03 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	set_angle(t_all *a)
{
	float	angle;

	angle = a->world->player.dir - (a->world->player.fov / 2.0f);
	if (angle < 0.0f)
		angle = 360.0f + angle;
	return (angle);
}

float	set_angle2(t_all *a)
{
	float	angle;

	angle = (a->world->player.dir + (a->world->player.fov / 2.0f)) + 1.0f;
	if (angle > 360.0f)
		angle = angle - 360.0f;
	return (angle);
}

float	incr_angle(float angle)
{
	angle += 0.10f;
	if (angle > 360.0f)
		angle = angle - 360.0f;
	return (angle);
}
