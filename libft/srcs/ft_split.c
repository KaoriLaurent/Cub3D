/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:52:19 by requinch          #+#    #+#             */
/*   Updated: 2022/05/01 16:51:49 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	**ft_malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static unsigned int	ft_get_nb_strs(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}

static void	ft_get_next_str(char **next_str, unsigned int *next_str_len, char c)
{
	unsigned int	i;

	*next_str += *next_str_len;
	*next_str_len = 0;
	i = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*next_str_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	char			*next_str;
	unsigned int	i[3];

	if (!s)
		return (NULL);
	i[2] = ft_get_nb_strs(s, c);
	tab = (char **)malloc(sizeof(char *) * (i[2] + 1));
	if (!tab)
		return (NULL);
	i[0] = 0;
	next_str = (char *)s;
	i[1] = 0;
	while (i[0] < i[2])
	{
		ft_get_next_str(&next_str, &i[1], c);
		tab[i[0]] = (char *)malloc(sizeof(char) * (i[1] + 1));
		if (!tab[i[0]])
			return (ft_malloc_error(tab));
		ft_strlcpy(tab[i[0]], next_str, i[1] + 1);
		i[0]++;
	}
	tab[i[0]] = NULL;
	return (tab);
}
