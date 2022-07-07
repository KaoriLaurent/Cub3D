/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 04:24:32 by requinch          #+#    #+#             */
/*   Updated: 2021/10/26 16:44:09 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	int		u;
	int		mod;
	int		z;
	void	*sub;

	i = -1;
	if (!s)
		return (NULL);
	u = ft_strlen(s) - start;
	if (u > (int)len)
		mod = (int)len;
	else
		mod = u;
	sub = malloc(sizeof(char) * mod * (u > 0) + 1);
	if (!sub)
		return (NULL);
	z = ((u > (int)len) * (int)len + !(u > (int)len) * u);
	while (++i < z && u > 0)
		*(char *)(sub + i) = *(s + start + i);
	*(char *)(sub + i) = 0;
	return (sub);
}
