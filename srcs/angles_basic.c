/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:08:06 by requinch          #+#    #+#             */
/*   Updated: 2022/07/09 16:51:04 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	degtorad(short deg)
{
	float	f;
	
	f = deg * (PI / 180);
	return (f);
}

short	angle_add(short one, short two)
{
	return ((one + two) % 3600);
}

short	angle_sub(short one, short two)
{
	return ((one - two) % 3600);
}

short	angle_mul(short one, short factor)
{
	return ((one * factor) % 3600);
}

short	angle_div(short one, short factor)
{
	return ((one / factor) % 3600);
}
