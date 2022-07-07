/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 02:40:35 by requinch          #+#    #+#             */
/*   Updated: 2021/10/26 16:42:55 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (a > b)
	{
		n++;
		while (i < --n)
			a[n - 1] = b[n - 1];
	}
	else
	{
		while (i < n)
		{
			a[i] = b[i];
			i++;
		}
	}
	return (dest);
}
