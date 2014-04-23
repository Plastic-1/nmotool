/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 16:07:37 by aeddi             #+#    #+#             */
/*   Updated: 2013/11/27 16:12:36 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	res;

	res = ft_strlen(src);
	index = ft_strlen(dst);
	if (index < size)
		res += index;
	else
		res += size;
	if ((int)(size - ft_strlen(dst) - 1) > 0)
		ft_strncat(dst, src, size - ft_strlen(dst) - 1);
	return (res);
}
