/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:55:51 by aeddi             #+#    #+#             */
/*   Updated: 2013/11/27 15:43:35 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	char	*m;
	size_t	len2;

	m = (char *)s;
	len2 = 0;
	while (len2 < len)
	{
		m[len2] = (unsigned char)c;
		len2++;
	}
	return (s);
}
