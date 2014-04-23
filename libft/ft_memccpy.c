/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:07:13 by aeddi             #+#    #+#             */
/*   Updated: 2013/12/01 18:13:19 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char			*s1_bis;
	char			*s2_bis;
	int				check;
	unsigned char	c_bis;

	s1_bis = (char *)s1;
	s2_bis = (char *)s2;
	check = 0;
	c_bis = (unsigned char)c;
	while (*s2_bis != c_bis && n)
	{
		*s1_bis++ = *s2_bis++;
		n--;
	}
	if (*s2_bis == c_bis && n)
	{
		*s1_bis++ = *s2_bis++;
		check++;
	}
	if (!n && !check)
		return (NULL);
	return (s1_bis);
}
