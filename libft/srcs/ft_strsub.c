/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:08:36 by requinch          #+#    #+#             */
/*   Updated: 2021/12/14 15:09:21 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*str;

	i = start;
	j = 0;
	if (s)
	{
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (!(str))
			return (NULL);
		while (j < len)
		{
			str[j] = s[i];
			j++;
			i++;
		}
		str[j] = '\0';
		return (str);
	}
	else
		return (0);
}
