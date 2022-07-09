/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:54:45 by requinch          #+#    #+#             */
/*   Updated: 2022/07/09 15:58:26 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/******************************************************************************/
/*			Includes														  */
/******************************************************************************/

# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

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
	ERR_ARG = 11,
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

typedef struct	s_position
{
	t_size	x;
	t_size	y;
} 				t_position;

typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct	s_resolution
{
	t_size	width;
	t_size	height;
}				t_resolution;

/***
****	fov :			0 - 3599
****	direction :		0 - 3599
***/

typedef struct	s_player_info
{
	t_position	pos;
	short		fov;
	short		direction;
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
	char			**map;
	t_size			tile_size;
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

/*	errors.c			*/

void		*error_free(t_errorcode code, void *ptr);
int			error_int_ret(t_errorcode code, int ret);
int			error_int_free(t_errorcode code, int ret, void *ptr);
void		*throw_error(t_errorcode code);

/*	reader.c			*/

char		*read_file(char *filepath);

/*	parser_frame.c		*/

t_boolean	parsing(char *cub_raw);

/*	parser_routines.c	*/

short	parse_texture(char *line, t_counter step);
short	parse_color(char *line, t_counter step);
short	parse_map(char *line, int fd);
short	parse_rest(char *line, short gnl_ret);

/*	angles_basic.c		*/

short	angle_add(short one, short two);
short	angle_sub(short one, short two);
short	angle_mul(short one, short factor);
short	angle_div(short one, short factor);

/*	utils_parser.c		*/

unsigned int	get_max_length(char **map);
unsigned short	check_the_map(char **map);

/*	freedom.c			*/

int	free_map(char **map, int ret);

#endif