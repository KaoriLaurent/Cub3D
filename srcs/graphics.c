/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:19:59 by anbourge          #+#    #+#             */
/*   Updated: 2022/08/04 00:43:00 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	tex_init(t_vars *vars, char **paths)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		vars->tex[i].img = mlx_xpm_file_to_image(vars->mlx, paths[i], &vars->tex[i].width, &vars->tex[i].height);
		vars->tex[i].ptr = mlx_get_data_addr(vars->tex[i].img, &vars->tex[i].bpp, &vars->tex[i].size_line, &vars->tex[i].endian);
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
}

t_tex	*get_tex(t_vars *vars, t_rays *r)
{
	return (&vars->tex[r->side]);
	/*if (r->side == 0 || r->side == 2)
	{
		if ((int)vars->p->pos.y > r->wall_y)
			return (&vars->tex[1]);
		else if ((int)vars->p->pos.y <= r->wall_y)
			return (&vars->tex[0]);
	}
	else
	{
		if (vars->p->pos.x >= r->wall_x)
			return (&vars->tex[3]);
		else if (vars->p->pos.x < r->wall_x)
			return (&vars->tex[2]);	
	}
	return (&vars->tex[0]);*/
}

int	get_texture_color(int y, t_vars *vars, int start, float lh, t_rays *r)
{
	int			color;
	float		step;
	float		texPos;
	int 		texY;
	int			texX;
	t_tex		*tex;
	
	tex = get_tex(vars, r);
	step = 1.0 * tex->height / (lh * 1.4);
	texPos = (start - 720.0 / 2.0 + lh / 2.0) * step;
	texPos += step * (y - start);
	texY = (int)texPos & (tex->height - 1);
	if (r->side == 0 || r->side == 2)
		texX = (r->y - r->wall_y) * tex->height;
	else
		texX = (r->x - r->wall_x) * tex->height;
	color = *(int *)(tex->ptr + (4 * texY * tex->height) + (texX * 4));
	return (color);
}

void	graphics(t_rays *r, t_vars *vars)
{
	int	i;
	int	j;
	int	k;
	int	l;
	float	lh;
	int	start;
	int	end;
	int	color[2];
	
	i = 1;
	l = 1280;
	color[0] = 0x00FF0000;
	color[1] = 0x000700A3;
	while (r)
	{
		lh = (2.0 * 720.0) / r->dist;
		start = (-lh / 2) + (720 / 2);
		if (start < 0)
			start = 0;
		end = (lh / 2) + (720 / 2);
		if (end >= 720)
			end = 719;
		j = -1;
		//printf("Distance ray (%f,%f) = %f\n", r->x, r->y, r->dist);
		if (i % 6 == 0)
		{
			while (++j < 2)
			{
				k = -1;
				while (k < start)
					my_mlx_pixel_put(&vars->img, l, ++k, 0x0000B5E2);
				k--;
				while (k++ <= end)
					my_mlx_pixel_put(&vars->img, l, k, get_texture_color(k, vars, start, lh, r));
				k--;
				while (k <= 720)
					my_mlx_pixel_put(&vars->img, l, ++k, 0x00009A17);
				l--;
			}
		}
		else
		{
			while (++j < 3)
			{
				k = -1;
				while (k < start)
					my_mlx_pixel_put(&vars->img, l, ++k, 0x0000B5E2);
				k--;
				while (k++ <= end)
					my_mlx_pixel_put(&vars->img, l, k, get_texture_color(k, vars, start, lh, r));
				k--;
				while (k <= 720)
					my_mlx_pixel_put(&vars->img, l, ++k, 0x00009A17);
				l--;
			}
		}
		i++;
		r = r->next;
	}
}