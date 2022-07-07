/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:08:06 by requinch          #+#    #+#             */
/*   Updated: 2022/07/07 18:08:06 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

short	angle_add(short one, short two)
{
	return ((one + two) % 360);
}

short	angle_sub(short one, short two)
{
	return ((one - two) % 360);
}

short	angle_mul(short one, short factor)
{
	return ((one * factor) % 360);
}

short	angle_div(short one, short factor)
{
	return ((one / factor) % 360);
}
