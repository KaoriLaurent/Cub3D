/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: requinch <requinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:29:33 by requinch          #+#    #+#             */
/*   Updated: 2021/10/26 16:42:00 by requinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			temp = ft_lstlast(*(alst));
			temp->next = new;
		}
	}
}
