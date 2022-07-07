/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:54:45 by requinch          #+#    #+#             */
/*   Updated: 2022/07/07 00:54:45 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/******************************************************************************/
/*			Defines															  */
/******************************************************************************/

# define EXPECTED_FILEFORMAT ".cub"

/******************************************************************************/
/*			Simple typedefs													  */
/******************************************************************************/

typedef unsigned short t_counter;
typedef unsigned int t_size;

/******************************************************************************/
/*			Enums															  */
/******************************************************************************/

typedef enum boolean
{
	TRUE = 1,
	FALSE = 0,
} t_boolean;

typedef enum errcode
{
	ERR_UNDEFINED = 0,
	ERR_MALLOC = 1,
	ERR_FILEFORMAT = 20,
	ERR_FILEPATH = 21,
	ERR_OPEN = 30,
	ERR_READ = 31,
} t_errorcode;

/******************************************************************************/
/*			Structures														  */
/******************************************************************************/

/***
****	resolution :	[0] : width
****					[1] : height
****	tex_path :		[0] : N
****					[1] : S
****					[2] : E
****					[3] : W
***/

typedef struct map_info
{
	char			*raw;
	unsigned int	width;
	unsigned int	height;
	unsigned int	**map;
	unsigned short	resolution[2];
	char			*tex_path[4];
	unsigned short	ground_clr;
	unsigned short	ceiling_clr;
} t_map_info;

/******************************************************************************/
/*			Function declarations											  */
/******************************************************************************/

/*	errors.c	*/

void	*err_fr(t_errorcode code, void *ptr);
void	*throw_error(t_errorcode code);

/*	reader.c	*/

char	*read_file(char *filepath);

/*	parser.c	*/

t_boolean	parsing(char *cub_raw);

#endif