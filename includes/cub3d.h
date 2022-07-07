/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:54:45 by requinch          #+#    #+#             */
/*   Updated: 2022/07/07 17:14:21 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/******************************************************************************/
/*			Includes														  */
/******************************************************************************/

# include "../libft/includes/libft.h"

/******************************************************************************/
/*			Defines															  */
/******************************************************************************/

# define EXPECTED_FILEFORMAT ".cub"

/******************************************************************************/
/*			Simple typedefs													  */
/******************************************************************************/

typedef unsigned short	t_counter;
typedef unsigned int	t_size;

/******************************************************************************/
/*			Enums															  */
/******************************************************************************/

typedef enum	boolean
{
	TRUE = 1,
	FALSE = 0,
}				t_boolean;

typedef enum	errcode
{
	ERR_UNDEFINED = 0,
	ERR_MALLOC = 10,
	ERR_MANY_ARG = 11,
	ERR_GNL = 12,
	ERR_FILEFORMAT = 20,
	ERR_FILEPATH = 21,
	ERR_FILECONTENT = 22,
	ERR_OPEN = 30,
	ERR_READ = 31,
}				t_errorcode;

/******************************************************************************/
/*			Structures														  */
/******************************************************************************/

typedef struct	s_vector
{
	unsigned int	x;
	unsigned int	y;
} 				t_vector;

typedef struct	s_resolution
{
	unsigned int	width;
	unsigned int	height;
}				t_resolution;

/***
****	fov :			0 - 360
****	direction :		0 - 360
****	Maybe add other properties
***/

typedef struct s_camera
{
	t_vector	r_fov;
	t_vector	l_fov;
}				t_camera;

typedef struct	s_player_info
{
	t_vector	pos;
	t_camera	camera;
}				t_player_info;

/***
****	resolution :	[0] : width
****					[1] : height
****	tex_path :		[0] : N
****					[1] : S
****					[2] : E
****					[3] : W
***/

typedef struct	s_map_info
{
	char			*raw;
	t_resolution	map_res;
	unsigned int	**map;
	char			*tex_path[4];
	unsigned int	ground_clr;
	unsigned int	ceiling_clr;
}				t_map_info;

typedef struct	s_world
{
	t_map_info		map;
	t_player_info	player;
	
}				t_world;

/******************************************************************************/
/*			Function declarations											  */
/******************************************************************************/

/*	errors.c	*/

void		*err_fr(t_errorcode code, void *ptr);
void		*throw_error(t_errorcode code);

/*	reader.c	*/

char		*read_file(char *filepath);

/*	parser.c	*/

t_boolean	parsing(char *cub_raw);

/*	angles_basic.c	*/

short	angle_add(short one, short two);
short	angle_sub(short one, short two);
short	angle_mul(short one, short two);
short	angle_div(short one, short two);

#endif