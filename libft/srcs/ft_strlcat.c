/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 04:19:26 by requinch          #+#    #+#             */
/*   Updated: 2021/10/26 16:43:37 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	i;
	int	u;

	u = 0;
	i = ft_strlen(dst);
	if (size == 0)
		return (ft_strlen(src));
	if ((int)size < i)
		return (ft_strlen(src) + size);
	while (src[u] && u < (int)size - i - 1)
	{
		dst[i + u] = src[u];
		u++;
	}
	if (u < (int)size)
		dst[i + u] = 0;
	return (ft_strlen(src) + i);
}
