/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:58:53 by requinch          #+#    #+#             */
/*   Updated: 2022/01/05 15:11:09 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* Not meant to be used without ft_isfloat beforehand ! */

double	ft_atof(char *str)
{
	long double	db;
	int			neg;
	int			i;
	int			dot;

	i = ft_strlen(str);
	neg = 0 + (str[0] == 45);
	dot = 1 - (ft_strchr(str, '.') != NULL);
	db = 0;
	while (--i >= neg && str[i])
	{
		if (str[i] == 46)
		{
			dot = 1;
			db /= 100;
			continue ;
		}
		if (dot == 0)
			db /= 10;
		else
			dot++;
		db += (str[i] - 48) * ft_int_pow(10, (dot > 0)
				* (dot - 2) + (dot == 0));
	}
	return (db * (1 - 2 * (neg == 1)));
}
