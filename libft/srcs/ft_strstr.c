/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:18:19 by anbourge          #+#    #+#             */
/*   Updated: 2022/05/03 17:21:43 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	if (to_find[0] == '\0')
		return (str);
	k = -1;
	while (str[++k] != '\0')
	{
		i = 0;
		j = 0;
		while (to_find[i] && str[i])
		{
			if (str[i] != to_find[i])
				j = 1;
			i++;
		}
		if (j == 0)
			return (str);
	}
	return (NULL);
}
