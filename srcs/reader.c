/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:36:09 by requinch          #+#    #+#             */
/*   Updated: 2022/07/07 01:36:09 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
**	Requires :
**	first to be allocated, second not to be.
*/

char	*ft_strfcat(char *first, char *second)
{
	char	*cat;
	t_size	size;
	t_counter	index_one;
	t_counter	index_two;

	size = ft_strlen(first) + ft_strlen(second) + 1;
	index_one = 0;
	index_two = 0;
	cat = ft_calloc(size, sizeof(char));
	if (!cat)
		return(throw_error(ERR_MALLOC));
	while (first && first[index_one])
	{
		cat[index_one] = first[index_one];
		index_one += 1;
	}
	while (second && second[index_two])
	{
		cat[index_one + index_two] = second[index_two];
		index_two += 1;
	}
	cat[index_one + index_two] = 0;
	free(first);
	return (cat);
}

t_boolean	check_fileformat(char *filepath, char *expected)
{
	t_counter	index;
	t_size	file_len;
	t_size	ext_len;

	if (!expected || !(*expected))
		return (TRUE);
	file_len = ft_strlen(filepath);
	ext_len = ft_strlen(expected);
	if (ft_strlen(expected) > ft_strlen(filepath))
		return (FALSE);
	index = 0;
	while (index < ext_len)
	{
		if (filepath[file_len - ext_len + index] != expected[index])
			return (FALSE);
		index += 1;
	}
	return (TRUE);
}

char	*read_file(char *filepath)
{
	char	*read;
	char	c;
	short	fd;
	short	readret;

	if (!filepath || !(*filepath))
		return (throw_error(ERR_FILEPATH));
	if (!check_fileformat(filepath, EXPECTED_FILEFORMAT))
		return (throw_error(ERR_FILEFORMAT));
	read = ft_calloc(1, sizeof(char));
	if (!read)
		return (throw_error(ERR_MALLOC));
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (err_fr(ERR_OPEN, read));
	readret = 1;
	while (readret)
	{
		readret = read(fd, &c, 1);
		if (readret < 0)
			return (err_fr(ERR_READ, read));
		read = ft_strfcat(read, c);
	}
	close(fd);
	return (read);
}