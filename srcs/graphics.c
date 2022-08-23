/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:19:59 by anbourge          #+#    #+#             */
/*   Updated: 2022/08/23 16:41:06 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	tex_init(t_vars *vars, char **paths)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		vars->tex[i].img = mlx_xpm_file_to_image(vars->mlx, paths[i],
				&vars->tex[i].width, &vars->tex[i].height);
		vars->tex[i].ptr = mlx_get_data_addr(vars->tex[i].img,
				&vars->tex[i].bpp, &vars->tex[i].size_line,
				&vars->tex[i].endian);
	}
}

int	get_texture_color(int *s, t_vars *vars, float lh, t_rays *r)
{
	int			color;
	float		step;
	float		texpos;
	int			tex[2];
	t_tex		*t;

	t = &vars->tex[r->side];
	step = 1.0 * t->height / lh;
	texpos = (s[0] - WIN_HEIGHT_F / 2.0 + lh / 2.0) * step;
	texpos += step * (s[1] - s[0]);
	tex[1] = (int)texpos & (t->height - 1);
	if (r->side == 0 || r->side == 2)
		tex[0] = (r->y - r->wall_y) * t->height;
	else
		tex[0] = (r->x - r->wall_x) * t->height;
	color = *(int *)(t->ptr + (4 * tex[1] * t->height) + (tex[0] * 4));
	return (color);
}

int	graphics2(t_all *a, int *i, int *limit, float lh)
{
	int	s[2];

	s[0] = limit[0];
	while (++i[1] < 3)
	{
		i[2] = -1;
		while (i[2] < limit[0])
			my_mlx_pixel_put(&a->vars->img, i[3], ++i[2],
				a->world->map.ceiling_clr);
		i[2]--;
		while (i[2]++ <= limit[1])
		{
			s[1] = i[2];
			my_mlx_pixel_put(&a->vars->img, i[3], i[2],
				get_texture_color(s, a->vars, lh, a->r));
		}
		i[2]--;
		while (i[2] <= WIN_HEIGHT)
			my_mlx_pixel_put(&a->vars->img, i[3], ++i[2],
				a->world->map.ground_clr);
		i[3]--;
	}
	return (i[3]);
}

int	graphics3(t_all *a, int *i, int *limit, float lh)
{
	int	s[2];

	s[0] = limit[0];
	while (++i[1] < 4)
	{
		i[2] = -1;
		while (i[2] < limit[0])
			my_mlx_pixel_put(&a->vars->img, i[3], ++i[2],
				a->world->map.ceiling_clr);
		i[2]--;
		while (i[2]++ <= limit[1])
		{
			s[1] = i[2];
			my_mlx_pixel_put(&a->vars->img, i[3], i[2],
				get_texture_color(s, a->vars, lh, a->r));
		}
		i[2]--;
		while (i[2] <= WIN_HEIGHT)
			my_mlx_pixel_put(&a->vars->img, i[3], ++i[2],
				a->world->map.ground_clr);
		i[3]--;
	}
	return (i[3]);
}

void	graphics(t_all *a)
{
	int		i[4];
	float	lh;
	int		limit[2];

	i[0] = 0;
	i[3] = WIN_WIDTH - 1;
	while (a->r)
	{
		lh = (1.5 * WIN_HEIGHT_F) / a->r->dist;
		limit[0] = (-lh / 2) + (WIN_HEIGHT / 2);
		if (limit[0] < 0)
			limit[0] = 0;
		limit[1] = (lh / 2) + (WIN_HEIGHT / 2);
		if (limit[1] >= WIN_HEIGHT)
			limit[1] = WIN_HEIGHT - 1;
		i[1] = -1;
		if (i[0] % 5 == 0)
			i[3] = graphics3(a, i, limit, lh);
		else
			i[3] = graphics2(a, i, limit, lh);
		i[0]++;
		a->r = a->r->next;
	}
}
