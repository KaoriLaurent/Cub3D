/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 01:40:00 by requinch          #+#    #+#             */
/*   Updated: 2021/11/27 18:32:03 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isfloat(char *str)
{
	int	flag;
	int	i;

	flag = 0;
	i = -1;
	if (str[0] == '-')
		i++;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (0);
		if (str[i] == '.')
		{
			if (flag || i == 0 || str[i - 1] == '-')
				return (0);
			flag = 1;
		}
	}
	return (1);
}
