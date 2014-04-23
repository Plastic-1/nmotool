/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 20:11:10 by aeddi             #+#    #+#             */
/*   Updated: 2014/04/16 14:25:24 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_bis;

	s_bis = (unsigned char*)s;
	while (n > 0)
	{
		if (*s_bis == (unsigned char)c)
			return (s_bis);
		n--;
		s_bis++;
	}
	return (NULL);
}
