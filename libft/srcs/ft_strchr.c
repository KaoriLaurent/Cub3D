/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:00:52 by requinch          #+#    #+#             */
/*   Updated: 2022/03/22 15:27:30 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = -1;
	if (!s)
		return (NULL);
	if (c == 0)
		return ((char *)&s[ft_strlen(s)]);
	while (s[++i])
		if (s[i] == c)
			return ((char *)&s[i]);
	return (NULL);
}
