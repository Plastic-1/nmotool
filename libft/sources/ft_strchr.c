/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:50:20 by aeddi             #+#    #+#             */
/*   Updated: 2014/05/19 19:33:01 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = ft_strlen(s);
	while (index && *s != (char)c)
	{
		s++;
		index--;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
