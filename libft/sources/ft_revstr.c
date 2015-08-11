/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 17:02:02 by aeddi             #+#    #+#             */
/*   Updated: 2014/05/19 19:28:10 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_revstr(char *s)
{
	size_t	size;
	size_t	index;
	char	temp;

	size = ft_strlen(s) - 1;
	index = 0;
	while (size > index)
	{
		temp = s[index];
		s[index] = s[size];
		s[size] = temp;
		size--;
		index++;
	}
	return (s);
}
