/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:04:22 by aeddi             #+#    #+#             */
/*   Updated: 2014/05/19 19:52:15 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static char	*spliter(char const *s, char c)
{
	size_t	index;
	char	*splited;

	index = 0;
	while (s[index] && s[index] != c)
		index++;
	splited = ft_strnew(index);
	if (splited)
	{
		index = 0;
		while (s[index] && s[index] != c)
		{
			splited[index] = s[index];
			index++;
		}
	}
	return (splited);
}

static char	**tab_maker(char const *s, char c)
{
	size_t	index;
	size_t	count;
	char	**tab;

	index = 0;
	count = 0;
	while (s[index])
	{
		if (s[index] != c)
		{
			count++;
			while (s[index] && s[index] != c)
				index++;
		}
		index++;
	}
	tab = (char **)ft_memalloc(sizeof(char *) * (count + 1));
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	index;
	size_t	count;
	char	**tab;

	index = 0;
	count = 0;
	if (!s)
		return (NULL);
	tab = tab_maker(s, c);
	if (tab)
	{
		while (s[index])
		{
			if (s[index] != c)
			{
				tab[count] = spliter(s + index, c);
				count++;
				while (s[index] != c && s[index] != '\0')
					index++;
			}
			if (s[index])
				index++;
		}
	}
	return (tab);
}
