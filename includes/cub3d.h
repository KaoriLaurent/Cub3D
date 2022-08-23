/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:54:45 by requinch          #+#    #+#             */
/*   Updated: 2022/08/23 16:23:08 by anbourge         ###   ########.fr       */
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
# include <mlx.h>

/******************************************************************************/
/*			Defines															  */
/******************************************************************************/

# define EXPECTED_FILEFORMAT ".cub"
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define WIN_WIDTH_F 1920.0f
# define WIN_HEIGHT_F 1080.0f
# define PI 3.14159265f

/******************************************************************************/
/*			Simple typedefs													  */
/******************************************************************************/

typedef unsigned short	t_counter;
typedef unsigned int	t_size;

/******************************************************************************/
/*			Enums															  */
/******************************************************************************/

typedef enum e_boolean
{
	TRUE = 1,
	FALSE = 0,
}				t_boolean;

typedef enum e_errcode
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

typedef struct s_position
{
	float	x;
	float	y;
}				t_position;

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_resolution
{
	t_size	width;
	t_size	height;
}				t_resolution;

typedef struct s_player
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

typedef struct s_map
{
	char			*raw;
	int				**map;
	t_position		start_pos;
	char			*tex_path[4];
	unsigned int	ground_clr;
	unsigned int	ceiling_clr;
}				t_map;

typedef struct s_world
{
	t_map		map;
	t_player	player;
}				t_world;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_tex
{
	void	*ptr;
	void	*img;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}				t_tex;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_data		img;
	t_tex		tex[4];
}				t_vars;

typedef struct s_rays
{
	float	x;
	float	y;
	float	dist;
	int		wall_x;
	int		wall_y;
	int		side;
	void	*next;
}				t_rays;

typedef struct s_all
{
	t_vars		*vars;
	t_world		*world;
	t_rays		*r;
}				t_all;

/******************************************************************************/
/*			Function declarations											  */
/******************************************************************************/

/*	algorithm.c			*/

float			get_dir(float dir, int input);
int				get_wall_side2(float *diff, float *tmp, int *ret);
int				get_wall_side(t_position pos, int wall_x, int wall_y);
void			algorithm(t_all *a, int i);

/*	angles_basic.c		*/

float			degtorad(float deg);
short			angle_add(short one, short two);
short			angle_sub(short one, short two);
short			angle_mul(short one, short factor);
short			angle_div(short one, short factor);

/*	debug.c				*/

void			print_world(t_world world);
void			print_map_char(char **map);
void			print_map_int(int **map);
void			step_debug_map_filler(char *raw, int index);
void			step_debug_map_parser(char **map, t_vector pos, t_counter step);

/*	errors.c			*/

void			*error_freeptrptr(t_errorcode code, void **ptr);
void			*error_free(t_errorcode code, void *ptr);
int				error_int_ret(t_errorcode code, int ret);
int				error_int_free(t_errorcode code, int ret, void *ptr);
void			*throw_error(t_errorcode code);

/*	filling_utils.c 	*/

char			*get_next_element(char *raw, t_counter step);
int				get_color(char *raw);
char			*get_texpath(char *raw);
t_vector		osef(t_vector current, int *steak);

/*	filling.c			*/

void			fill_world(t_world *world);

/*	freedom.c			*/

int				free_world(t_world	*world);
int				free_text(char **text, int ret);
int				free_return(void *ptdr, int ret);
void			freefree(void *uno, void *dos);
int				freefree_ret(void *uno, void *dos, int ret);

/*	graphics.c			*/

void			tex_init(t_vars *vars, char **paths);
int				get_texture_color(int *s, t_vars *vars, float lh, t_rays *r);
int				graphics2(t_all *a, int *i, int *limit, float lh);
int				graphics3(t_all *a, int *i, int *limit, float lh);
void			graphics(t_all *a);

/*	movements.c			*/

int				my_key_hook(int keycode, t_all *all);
int				render_next_frame(t_all *a);
int				check_player_movement(int keycode, t_world *world);
void			player_camera_movements(int keycode, t_player *player);
void			player_movements(int keycode, t_player *player);

/*	reader.c			*/

t_boolean		check_fileformat(char *filepath, char *expected);
char			*read_file(char *filepath);

/*	parser_frame.c		*/

t_boolean		parsing(char *cub_raw);

/*	parser_map.c		*/

unsigned short	check_the_map(char **map, t_size height);

/*	parser_routines.c	*/

short			parse_texture(char *line, t_counter step);
short			parse_color(char *line, t_counter step);
short			parse_upper(char *line);
short			parse_map(char *line, int fd, int gnl_ret);
short			parse_rest(char *line, short gnl_ret);

/*	parser_utils.c		*/

t_boolean		is_edge(char **map, t_vector pos);
t_vector		shift_north(t_vector pos);
t_vector		shift_south(t_vector pos);
t_vector		shift_west(t_vector pos);
t_vector		shift_east(t_vector pos);

/*	raycasting.c		*/

t_position		next_intersection(float angle, t_player p, float r);
void			get_ray(int i, t_position p, t_all *a, int *ray);
void			first_ray(t_all *all, t_position pos, t_position player_pos,
					int *wall);
void			add_ray(t_all *all, t_position pos, t_position player_pos,
					int *wall);
float			set_r(float angle, t_position pos, int i, int a);

/*	reader.c			*/

char			*read_file(char *filepath);

/*	utils.c				*/

int				numlen(int i);
int				is_num_or_comma(char *str, int index, int stepbro);
void			set_angles(t_all *a, float *f);
void			set_ratios(float *f);
float			incr_angle(float angle);

/*	window.c			*/

char			**mapcpy(char **map, int height);
void			window_init(t_all *a);
int				my_exit_hook(t_all *all);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif