/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 04:21:51 by requinch          #+#    #+#             */
/*   Updated: 2021/10/26 16:42:41 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned long	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		if (*(unsigned char *)(dest + i) == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
