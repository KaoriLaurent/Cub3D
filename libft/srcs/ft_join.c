/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:58:57 by anbourge          #+#    #+#             */
/*   Updated: 2022/05/04 17:25:37 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(char **arg)
{
	int	ret;
	int	i;
	int	j;

	ret = 0;
	i = -1;
	while (arg && arg[++i])
	{
		j = 0;
		while (arg && arg[i][j])
			j++;
		ret += j;
	}
	ret += i;
	return (ret);
}

char	*ft_join(char **arg, t_cmd *cmd)
{
	char	*res;
	int		i;
	int		j;
	int		k;
	int		size;

	if (!arg || !arg[0])
		return (NULL);
	size = ft_size(arg);
	res = malloc(sizeof(char) * size + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = -1;
	while (i < (size - 1) && arg[++j])
	{
		k = 0;
		while (arg && arg[j][k])
			res[i++] = arg[j][k++];
		if (cmd->spaces[j + 2] == 1 && arg[j + 1])
			res[i++] = ' ';
	}
	res[i] = '\0';
	return (res);
}
