/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:31:55 by requinch          #+#    #+#             */
/*   Updated: 2022/07/30 00:23:09 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	free_text(char **text, int ret)
{
	unsigned int	x;

	x = 0;
	while (text[x])
	{
		free(text[x]);
		x += 1;
	}
	free(text);
	return (ret);
}

int	free_return(void *ptdr, int ret)
{
	free (ptdr);
	return (ret);
}