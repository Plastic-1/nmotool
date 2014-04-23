/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:33:47 by aeddi             #+#    #+#             */
/*   Updated: 2013/11/27 16:15:00 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	int		index;
	int		match;

	index = ft_strlen(s) + 1;
	match = 0;
	while (index)
	{
		if (*s == (char)c)
		{
			last = (char *)s;
			match++;
		}
		s++;
		index--;
	}
	if (match)
		return (last);
	return (NULL);
}
