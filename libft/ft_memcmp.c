/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:24:18 by aeddi             #+#    #+#             */
/*   Updated: 2013/11/27 15:41:20 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_bis;
	unsigned char	*s2_bis;
	int				diff;

	s1_bis = (unsigned char *)s1;
	s2_bis = (unsigned char *)s2;
	while (*s1_bis == *s2_bis && n > 0)
	{
		s1_bis++;
		s2_bis++;
		n--;
	}
	if (n != 0)
	{
		diff = *s1_bis - *s2_bis;
		return (diff);
	}
	return (0);
}
