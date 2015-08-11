/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 19:06:10 by aeddi             #+#    #+#             */
/*   Updated: 2014/05/19 19:53:22 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	index;
	size_t	index2;
	char	*match;

	index = 0;
	if (!s2 || !*s2)
		return ((char *)s1);
	while (s1[index])
	{
		index2 = index;
		match = (char *)s2;
		while (s1[index2] == *match || *match == '\0')
		{
			if (!*match)
				return ((char *)s1 + index);
			index2++;
			match++;
		}
		index++;
	}
	return (NULL);
}
