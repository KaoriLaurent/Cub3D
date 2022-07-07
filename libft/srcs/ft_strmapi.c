/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 04:26:53 by requinch          #+#    #+#             */
/*   Updated: 2021/10/26 16:43:51 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*api;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	api = malloc(sizeof(char) * (i + 1));
	if (!api)
		return (NULL);
	*(api + i) = 0;
	while (--i >= 0)
		*(api + i) = (f)(i, *(s + i));
	return (api);
}
