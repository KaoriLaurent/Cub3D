/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:27:01 by anbourge          #+#    #+#             */
/*   Updated: 2022/08/22 19:15:11 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	window_init(t_all *a)
{
	a->vars->mlx = mlx_init();
	a->vars->win = mlx_new_window(a->vars->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	a->vars->img.img = mlx_new_image(a->vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	a->vars->img.addr = mlx_get_data_addr(a->vars->img.img,
			&a->vars->img.bits_per_pixel, &a->vars->img.line_length,
			&a->vars->img.endian);
	tex_init(a->vars, a->world->map.tex_path);
}

int	my_exit_hook(t_all *all)
{
	int		i;
	t_rays	*tmp;

	if (all->vars->img.img)
		mlx_destroy_image(all->vars->mlx, all->vars->img.img);
	if (all->vars->mlx && all->vars->win)
		mlx_destroy_window(all->vars->mlx, all->vars->win);
	i = -1;
	while (++i < 4)
		mlx_destroy_image(all->vars->mlx, all->vars->tex[i].img);
	free(all->vars);
	free_world(all->world);
	while (all->r)
	{
		tmp = all->r;
		all->r = all->r->next;
		free(tmp);
	}
	free(all);
	exit(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
