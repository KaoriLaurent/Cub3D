/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:14:06 by anbourge          #+#    #+#             */
/*   Updated: 2022/08/23 17:28:35 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	numlen(int i)
{
	int	numlen;

	numlen = 2;
	numlen += ((i / 10) > 0);
	numlen += + ((i / 100) > 0);
	return (numlen);
}

int	is_num_or_comma(char *str, int index, int stepbro)
{
	if (str[index] < '0' || str[index] > '9')
		return (0);
	while (str[index] >= '0' && str[index] <= '9')
		index++;
	if (stepbro == 3)
	{
		if (str[index])
			return (0);
		return (1);
	}
	if (str[index] != ',')
		return (0);
	return (is_num_or_comma(str, index + 1, stepbro + 1));
}

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
