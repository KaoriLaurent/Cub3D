/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:54:45 by requinch          #+#    #+#             */
/*   Updated: 2022/07/31 19:30:20 by requinch         ###   ########.fr       */
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
# include <stdio.h>
# include <math.h>
/*# include <mlx.h>*/

/******************************************************************************/
/*			Defines															  */
/******************************************************************************/

# define EXPECTED_FILEFORMAT ".cub"
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define PI 3.14159265

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
	float	x;
	float	y;
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

typedef struct	s_player
{
	t_position	pos;
	float		fov;
	float		dir;
}				t_player;

/***
****	tex_path :		[0] : N
****					[1] : S
****					[2] : W
****					[3] : E
***/

typedef struct	s_map
{
	char			*raw;
	int				**map;
	t_position		start_pos;
	char			*tex_path[4];
	unsigned int	ground_clr;
	unsigned int	ceiling_clr;
}				t_map;

typedef struct	s_world
{
	t_map		map;
	t_player	player;
	
}				t_world;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
}				t_vars;

typedef struct	s_rays
{
	float	x;
	float	y;
	float	dist;
	short	wall_x;
	short	wall_y;
	int		side;
	void	*next;
} 				t_rays;

typedef struct	s_all
{
	t_vars		*vars;
	t_player	*player;
}				t_all;

static int worldMap[24][24]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

/******************************************************************************/
/*			Function declarations											  */
/******************************************************************************/

/* algorithm.c			*/

float		get_dir(float dir, int input);
t_rays		*randomalgo(t_player *pp);

/*	filling_utils.c 	*/

char	*get_next_element(char	*raw);
char	*get_texpath(char *raw);

/*	filling.c			*/

/*	errors.c			*/

void		*error_freeptrptr(t_errorcode code, void **ptr);
void		*error_free(t_errorcode code, void *ptr);
int			error_int_ret(t_errorcode code, int ret);
int			error_int_free(t_errorcode code, int ret, void *ptr);
void		*throw_error(t_errorcode code);

/*	graphics.c			*/

void		graphics(t_rays *r, t_vars *vars);

/*	movements.c			*/

int			my_key_hook(int keycode, t_all *all);
void		player_movements(int keycode , t_all *a);
int			render_next_frame(void *YourStruct);

/*	reader.c			*/

char		*read_file(char *filepath);

/*	parser_frame.c		*/

t_boolean	parsing(char *cub_raw);

/*	parser_map.c		*/

unsigned short	check_the_map(char **map);

/*	parser_routines.c	*/

short	parse_texture(char *line, t_counter step);
short	parse_color(char *line, t_counter step);
short	parse_upper(char *line);
short	parse_map(char *line, int fd);
short	parse_rest(char *line, short gnl_ret);

/*	parser_utils.c		*/

t_boolean	is_edge(char **map, t_vector pos);
t_vector	shift_north(t_vector pos);
t_vector	shift_south(t_vector pos);
t_vector	shift_west(t_vector pos);
t_vector	shift_east(t_vector pos);

/*	raycasting.c		*/

t_position	next_intersection(float angle, t_player p, float r);
t_rays		*first_ray(t_position pos, t_position player_pos, int *wall);
t_rays		*add_ray(t_rays *r, t_position pos, t_position player_pos, int *wall);
float		set_r(float angle, t_position pos, int i, int a);

/*	angles_basic.c		*/

float	degtorad(float deg);
short	angle_add(short one, short two);
short	angle_sub(short one, short two);
short	angle_mul(short one, short factor);
short	angle_div(short one, short factor);

/*	sprites				*/

void	sprites();

/*	utils.c				*/

int		isInteger(float f);
void	print_map_char(char **map);
void	step_debug_map_parser(char **map, t_vector pos, t_counter step);

/*	window.c			*/

void	window_init(t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*	freedom.c			*/

int	free_text(char **text, int ret);
int	free_return(void *ptdr, int ret);

#endif