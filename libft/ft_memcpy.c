/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:04:48 by aeddi             #+#    #+#             */
/*   Updated: 2014/04/16 14:26:06 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char	*s1_bis;
	char	*s2_bis;

	s1_bis = (char *)s1;
	s2_bis = (char *)s2;
	while (n > 0)
	{
		n--;
		s1_bis[n] = s2_bis[n];
	}
	return (s1);
}
