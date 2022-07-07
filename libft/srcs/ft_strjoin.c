/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 04:24:56 by requinch          #+#    #+#             */
/*   Updated: 2022/07/08 01:05:26 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	void	*cat;
	int		i;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	cat = malloc(sizeof(char *) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!cat)
		return (NULL);
	while (++i < ft_strlen(s1))
		*(unsigned char *)(cat + i) = *(s1 + i);
	i--;
	while (++i < ft_strlen(s1) + ft_strlen(s2))
		*(unsigned char *)(cat + i) = *(s2 + i - ft_strlen(s1));
	*(unsigned char *)(cat + i) = 0;
	return (cat);
}
