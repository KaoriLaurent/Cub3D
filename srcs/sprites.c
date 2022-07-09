/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:41:06 by anbourge          #+#    #+#             */
/*   Updated: 2022/07/08 18:10:30 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	*create_sprite(t_vars *vars, char *tex_path)
{
	void	*sprite;
	int		pos[2];

	sprite = mlx_xpm_file_to_image(vars->mlx, tex_path, &pos[0], &pos[1]);
	return (sprite);
}