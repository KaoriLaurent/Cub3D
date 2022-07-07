/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 04:14:06 by requinch          #+#    #+#             */
/*   Updated: 2021/10/26 16:41:09 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(char *str)
{
	long long	var[3];

	var[2] = 0;
	var[0] = 0;
	while (str[var[2]] == 32 || str[var[2]] == '\t' || str[var[2]] == '\n'
		|| str[var[2]] == '\v' || str[var[2]] == '\f' || str[var[2]] == '\r')
		var[2]++;
	var[1] = 1 - (str[var[2]] == 45) * 2;
	var[2] += (str[var[2]] == 45) + (str[var[2]] == 43);
	while (str[var[2]] > 47 && str[var[2]] < 58)
		var[0] = var[0] * 10 + (str[var[2]++] - 48);
	return (var[1] * var[0]);
}
