/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 16:06:07 by aeddi             #+#    #+#             */
/*   Updated: 2013/12/22 22:02:07 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
