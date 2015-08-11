/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:28:08 by aeddi             #+#    #+#             */
/*   Updated: 2014/05/19 19:44:18 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = ft_strlen(dest);
	while (*src && n > 0)
	{
		dest[i] = *src;
		src++;
		i++;
		n--;
	}
	dest[i] = '\0';
	return (dest);
}
