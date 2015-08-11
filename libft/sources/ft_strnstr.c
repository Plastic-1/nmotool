/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 15:41:40 by aeddi             #+#    #+#             */
/*   Updated: 2014/05/19 19:48:45 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	index;
	size_t	index2;
	size_t	n2;
	char	*match;

	index = 0;
	n++;
	if (!s2 || !*s2)
		return ((char *)s1);
	while (s1[index] && n)
	{
		index2 = index;
		n2 = n;
		match = (char *)s2;
		while ((s1[index2] == *match || *match == '\0') && n2--)
		{
			if (*match == '\0')
				return ((char *)s1 + index);
			index2++;
			match++;
		}
		n--;
		index++;
	}
	return (NULL);
}
