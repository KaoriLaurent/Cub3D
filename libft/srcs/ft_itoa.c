/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 04:26:20 by requinch          #+#    #+#             */
/*   Updated: 2022/05/08 23:24:49 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

#include "libft.h"

static int	ft_nblen(int n)
{
	int		len;
	long	nb;

	len = 0;
	nb = n;
	if (nb <= 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	nb[2];

	nb[0] = n;
	nb[1] = ft_nblen(n);
	res = malloc(sizeof(char) * (nb[1] + 1));
	if (!res)
		return (NULL);
	res[nb[1]--] = '\0';
	if (nb[0] == 0)
	{
		res[0] = '0';
		return (res);
	}
	if (nb[0] < 0)
	{
		res[0] = '-';
		nb[0] = -nb[0];
	}
	while (nb[0] > 0)
	{
		res[nb[1]--] = (nb[0] % 10) + '0';
		nb[0] = nb[0] / 10;
	}
	return (res);
}
