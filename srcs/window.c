/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:27:01 by anbourge          #+#    #+#             */
/*   Updated: 2022/08/04 00:42:00 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	window_init(t_vars *vars)
{
	char	**paths;
	
	paths = malloc(sizeof(char *) * 4);
	if (!paths)
		return ;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	vars->img.img = mlx_new_image(vars->mlx, 1920, 1080);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length,
			&vars->img.endian);
	paths[0] = ft_strdup("./sprites/wood.xpm");
	paths[1] = ft_strdup("./sprites/redbrick.xpm");
	paths[2] = ft_strdup("./sprites/greystone.xpm");
	paths[3] = ft_strdup("./sprites/mossy.xpm");
	tex_init(vars, paths);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
