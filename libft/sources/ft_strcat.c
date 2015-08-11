/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:45:20 by aeddi             #+#    #+#             */
/*   Updated: 2014/05/19 19:32:35 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;

	i = ft_strlen(dest);
	while (*src)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
