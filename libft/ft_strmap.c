/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 12:22:48 by aeddi             #+#    #+#             */
/*   Updated: 2013/12/01 20:30:39 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	size_t	index;

	if (s != NULL && f != NULL)
	{
		fresh = ft_strnew(ft_strlen(s));
		index = 0;
		while (s[index])
		{
			fresh[index] = (*f)(s[index]);
			index++;
		}
		return (fresh);
	}
	return (NULL);
}
