/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 16:06:07 by aeddi             #+#    #+#             */
/*   Updated: 2014/05/19 19:47:04 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	index;

	str = (char *)malloc(size * sizeof(char) + 1);
	if (!str)
		return (NULL);
	index = 0;
	while (index <= size)
		str[index++] = '\0';
	return (str);
}
