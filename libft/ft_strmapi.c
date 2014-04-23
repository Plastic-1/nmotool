/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 21:17:41 by aeddi             #+#    #+#             */
/*   Updated: 2013/12/01 20:32:31 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	unsigned int	index;

	if (s != NULL && f != NULL)
	{
		fresh = ft_strnew(ft_strlen(s));
		index = 0;
		while (s[index])
		{
			fresh[index] = (*f)(index, s[index]);
			index++;
		}
		return (fresh);
	}
	return (NULL);
}
