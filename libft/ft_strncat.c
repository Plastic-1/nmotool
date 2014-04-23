/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:28:08 by aeddi             #+#    #+#             */
/*   Updated: 2013/11/27 16:09:10 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
