/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:50:08 by requinch          #+#    #+#             */
/*   Updated: 2022/07/08 01:04:50 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	void	*cpy;
	int		i;
	int		u;

	if (!s)
		return (NULL);
	u = ft_strlen(s);
	i = 0;
	cpy = malloc(u + 1);
	if (!cpy)
		return (NULL);
	while (i < u)
	{
		*(unsigned char *)(cpy + i) = *(unsigned char *)(s + i);
		i++;
	}
	*(unsigned char *)(cpy + i) = 0;
	return (cpy);
}
