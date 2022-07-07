/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:40:39 by anbourge          #+#    #+#             */
/*   Updated: 2022/01/05 15:30:18 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_line(char **save, int fd)
{
	int		len;
	char	*ret;

	len = 0;
	if (!save[fd])
		return (0);
	while (save[fd][len] && save[fd][len] != '\n')
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	len = 0;
	while (save[fd][len] && save[fd][len] != '\n')
	{
		ret[len] = save[fd][len];
		len++;
	}
	ret[len] = '\0';
	return (ret);
}

static char	*ft_save(char **save, int fd)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save[fd])
		return (0);
	while (save[fd][i] && save[fd][i] != '\n')
		i++;
	if (!save[fd][i])
	{
		free(save[fd]);
		return (0);
	}
	ret = malloc(sizeof(char) * ((ft_strlen(save[fd]) - i) + 1));
	if (!ret)
		return (0);
	i++;
	while (save[fd][i])
		ret[j++] = save[fd][i++];
	ret[j] = '\0';
	free(save[fd]);
	return (ret);
}

static int	ft_return(char **save, char **line, int res, int fd)
{
	*line = ft_line(save, fd);
	save[fd] = ft_save(save, fd);
	if (res == 0 && !save[fd])
		return (0);
	else
		return (1);
}

int	get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	static char		*save[4096];
	char			*tmp;
	int				res;

	res = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	while (!has_nl(save[fd]) && res != 0)
	{
		res = read(fd, buffer, BUFFER_SIZE);
		if (res == -1)
			return (-1);
		buffer[res] = '\0';
		if (save[fd] == NULL)
			save[fd] = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(save[fd], buffer);
			free(save[fd]);
			save[fd] = tmp;
		}
	}
	return (ft_return(save, line, res, fd));
}
