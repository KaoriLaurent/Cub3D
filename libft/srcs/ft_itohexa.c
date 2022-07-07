/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:40:43 by anbourge          #+#    #+#             */
/*   Updated: 2021/12/01 15:11:21 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itohexa(int nb)
{
	int		i;
	char	*hexa;
	char	*str;

	str = malloc(sizeof(char) * 6);
	if (!str)
		return (NULL);
	hexa = "0123456789ABCDEF";
	i = 5;
	while (i > -1)
	{
		str[i] = hexa[nb % 16];
		nb = nb / 16;
		i--;
	}
	return (str);
}
