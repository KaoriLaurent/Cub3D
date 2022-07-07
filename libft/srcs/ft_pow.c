/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:02:10 by requinch          #+#    #+#             */
/*   Updated: 2022/01/05 15:10:50 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long double	ft_int_pow(long double nb, int pow)
{
	if (pow == 0)
		return (1);
	if (pow == 1)
		return (nb);
	if (pow < 0)
		return (1 / ft_int_pow(nb, pow * -1));
	nb *= nb;
	return (ft_int_pow(nb, pow - 1));
}
