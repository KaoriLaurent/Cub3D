/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:40:39 by anbourge          #+#    #+#             */
/*   Updated: 2022/08/22 23:06:17 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	has_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*
**	Requires :
**	first to be allocated, second not to be.
*/

char	*ft_strfcat(char *first, char second)
{
	char		*cat;
	int			size;
	int			index;

	size = ft_strlen(first) + 2;
	index = 0;
	cat = ft_calloc(size, sizeof(char));
	while (first && first[index])
	{
		cat[index] = first[index];
		index += 1;
	}
	cat[index] = second;
	cat[index + 1] = 0;
	free(first);
	return (cat);
}

int	get_next_line(int fd, char **line)
{
	int		readret;
	char	c;

	if (fd < 0)
		return (-1);
	readret = 1;
	*line = calloc(1, sizeof(char));
	c = '\0';
	while (readret)
	{
		readret = read(fd, &c, 1);
		if (readret == -1)
		{
			free(*line);
			return (-1);
		}
		if (c == '\n')
			break ;
		*line = ft_strfcat(*line, c);
	}
	if (readret == 0)
		return (0);
	else
		return (1);
}
