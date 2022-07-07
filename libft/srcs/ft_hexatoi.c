/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:58:53 by anbourge          #+#    #+#             */
/*   Updated: 2021/12/01 15:11:10 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_power(int value, int power)
{
	int	res;

	res = 1;
	while (power > 0)
	{
		res = res * value;
		power--;
	}
	return (res);
}

int	ft_hexatoi(char *str, int j)
{
	int		i;
	int		length;
	int		value;
	int		hex;

	i = 0;
	while (ft_isalnum(str[j + i]))
		i++;
	i = i - 1;
	length = i;
	value = 0;
	while (i >= 0)
	{
		if (str[i + j] > 64 && str[i + j] < 71)
			hex = str[j + i] - 55;
		else if (str[i + j] > 96 && str[i + j] < 103)
			hex = str[j + i] - 87;
		else
			hex = str[j + i] - '0';
		value = value + (hex * ft_power(16, length - i));
		i--;
	}
	return (value);
}
