/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:48:01 by aeddi             #+#    #+#             */
/*   Updated: 2014/05/19 19:46:00 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	int	i;

	i = 0;
	while (n)
	{
		if (src[i] != '\0')
			dest[i] = src[i];
		else
			dest[i] = '\0';
		i++;
		n--;
	}
	return (dest);
}
