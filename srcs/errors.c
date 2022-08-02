/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:57:18 by requinch          #+#    #+#             */
/*   Updated: 2022/08/01 05:00:31 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	*error_freeptrptr(t_errorcode code, void **ptr)
{
	unsigned int	x;

	x = 0;
	while (ptr[x])
	{
		free(ptr[x]);
		x += 1;
	}
	free(ptr);
	return (throw_error(code));
}

void	*error_free(t_errorcode code, void *ptr)
{
	free(ptr);
	return (throw_error(code));
}

int	error_int_ret(t_errorcode code, int ret)
{
	throw_error(code);
	return (ret);
}

int	error_int_free(t_errorcode code, int ret, void *ptr)
{
	free(ptr);
	throw_error(code);
	return (ret);
}

void	*throw_error(t_errorcode code)
{
	if (code == ERR_UNDEFINED)
		ft_putendl_fd("Undefined error. Plz just stop", 2);
	else if (code == ERR_MALLOC)
		ft_putendl_fd("Malloc failed. Please check your RAM is installed.", 2);
	else if (code == ERR_ARG)
		ft_putendl_fd("Wrong number of arguments.", 2);
	else if (code == ERR_GNL)
		ft_putendl_fd("Get_Next_Line failed. Blaming Antoine now.", 2);
	else if (code == ERR_FILEFORMAT)
		ft_putendl_fd("Wrong file format. .caca is not a valid format.", 2);
	else if (code == ERR_FILEPATH)
		ft_putendl_fd("File path is invalid. Thought you were clever, huh.", 2);
	else if (code == ERR_FILECONTENT)
		ft_putendl_fd("File contents are invalid. I won't parse that shit.", 2);
	else if (code == ERR_OPEN)
		ft_putendl_fd("Failed to open. Call the LockPickingLawyer or smth", 2);
	else if (code == ERR_READ)
		ft_putendl_fd("Failed to... read. Yu-Gi-Oh players amirite", 2);
	return (NULL);
}
