/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 01:57:18 by requinch          #+#    #+#             */
/*   Updated: 2022/07/07 01:57:18 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	*err_fr(t_errorcode code, void *ptr)
{
	free(ptr);
	return(throw_error(code));
}

void	*throw_error(t_errorcode code)
{
	if (code == ERR_UNDEFINED)
		printf("Undefined error. Plz just stop");
	else if (code == ERR_MALLOC)
		printf("Malloc failed. Please check your RAM is properly installed.");
	else if (code == ERR_FILEFORMAT)
		printf("Wrong file format. And no, .caca is not a valid format.");
	else if (code == ERR_FILEPATH)
		printf("File path is invalid. Thought you were clever, huh.");
	else if (code == ERR_OPEN)
		printf("Failed to open. Call the LockPickingLawyer or smth");
	else if (code == ERR_READ)
		printf("Failed to... read. Cmon dude. Yu-Gi-Oh players I swear");
	return (NULL);
}