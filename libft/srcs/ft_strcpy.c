/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:08:47 by requinch          #+#    #+#             */
/*   Updated: 2022/01/11 16:23:27 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcpy(char *src)
{
	char	*new;
	int		i;

	i = -1;
	if (!src)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!new)
		return (NULL);
	while (src[++i])
		new[i] = src[i];
	new[i] = 0;
	return (new);
}
