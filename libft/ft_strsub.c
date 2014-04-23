/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 22:01:28 by aeddi             #+#    #+#             */
/*   Updated: 2013/12/30 12:21:06 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*fresh;
	unsigned int	index;

	fresh = ft_strnew(len);
	index = 0;
	if (!fresh || !s)
		return (NULL);
	while (len)
	{
		fresh[index] = s[start + index];
		index++;
		len--;
	}
	return (fresh);
}
