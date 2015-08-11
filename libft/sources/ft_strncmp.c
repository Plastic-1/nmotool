/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:27:05 by aeddi             #+#    #+#             */
/*   Updated: 2014/05/19 19:45:01 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 == *s2) && (*s1 != '\0') && (n > 0))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	if (*s1 != *s2)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (0);
}
