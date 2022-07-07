/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 04:25:29 by requinch          #+#    #+#             */
/*   Updated: 2021/10/26 16:44:06 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	char	*ft_strtrim_alloc(char const *s1, int offset, int inset)
{
	void	*trim;
	int		size;
	int		i;

	i = 0;
	size = (ft_strlen(s1) - (offset + inset));
	size = (size > 0) * (size + 1) + (size <= 0);
	trim = malloc((sizeof(char) * size));
	if (!trim)
		return (NULL);
	if (size < 1)
		*(char *)trim = 0;
	else
	{
		while (offset < ft_strlen(s1) - inset)
		{
			*(char *)(trim + i) = *(s1 + offset);
			i++;
			offset++;
		}
		*(char *)(trim + i) = 0;
	}
	return (trim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		index[3];
	int		counter[2];

	if (!s1 || !set)
		return (NULL);
	ft_bzero(index, sizeof(int) * 3);
	index[1] = ft_strlen(s1) - 1;
	ft_bzero(counter, sizeof(int) * 2);
	while (*(set + index[2]) && index[0] <= index[1])
	{
		while (*(s1 + index[0]) == *(set + index[2]))
		{
			counter[0]++;
			index[0]++;
			index[2] = 0;
		}
		while (*(s1 + index[1]) == *(set + index[2]))
		{
			counter[1]++;
			index[1]--;
			index[2] = 0;
		}
		index[2]++;
	}
	return (ft_strtrim_alloc(s1, counter[0], counter[1]));
}
