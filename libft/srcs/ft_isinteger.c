/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalldigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:12:52 by requinch          #+#    #+#             */
/*   Updated: 2021/11/17 20:25:38 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isinteger(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (i == 0 && str[i] == '-')
			i++;
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}
