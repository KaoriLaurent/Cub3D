/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:56:44 by anbourge          #+#    #+#             */
/*   Updated: 2022/07/07 18:03:36 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_vector	find_direction_vector(char direction, t_vector pos)
{
	t_vector	ret;
	
	if (direction == 'N')
	{
		ret.x = pos.x;
		ret.y = pos.y + 5;
	}
	else if (direction == 'S')
	{
		ret.x = pos.x;
		ret.y = pos.y - 5;
	}
	else if (direction == 'E')
	{
		ret.x = pos.x + 5;
		ret.y = pos.y;
	}
	else if (direction == 'W')
	{
		ret.x = pos.x - 5;
		ret.y = pos.y;
	}
	return (ret);
}

t_camera	create_camera(t_vector pos, char direction)
{
	t_vector	dir;

	dir = find_direction_vector(direction, pos);
	
}