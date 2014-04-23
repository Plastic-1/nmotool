/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 12:18:35 by aeddi             #+#    #+#             */
/*   Updated: 2014/01/22 12:20:06 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcount(const char *s1, const char *s2)
{
	int		count;
	char	*check;

	count = 0;
	check = (char *)s1;
	if (*s1 == '\0' || !s1 || *s2 == '\0' || !s2)
		return (count);
	while (check)
	{
		check = ft_strnstr(check, s2, ft_strlen(check));
		if (check)
		{
			count++;
			check += ft_strlen(s2);
		}
	}
	return (count);
}
