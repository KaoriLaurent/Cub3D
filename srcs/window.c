/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:27:01 by anbourge          #+#    #+#             */
/*   Updated: 2022/08/15 17:16:11 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	window_init(t_all *a)
{
	a->vars->mlx = mlx_init();
	a->vars->win = mlx_new_window(a->vars->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	a->vars->img.img = mlx_new_image(a->vars->mlx, 1920, 1080);
	a->vars->img.addr = mlx_get_data_addr(a->vars->img.img,
			&a->vars->img.bits_per_pixel, &a->vars->img.line_length,
			&a->vars->img.endian);
	tex_init(a->vars, a->world->map.tex_path);
}

int	my_exit_hook(t_all *all)
{
	if (all->vars->img.img)
		mlx_destroy_image(all->vars->mlx, all->vars->img.img);
	if (all->vars->mlx && all->vars->win)
		mlx_destroy_window(all->vars->mlx, all->vars->win);
	free(all->vars);
	free(all);
	free_world(all->world);
	exit(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
