/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 13:57:24 by aeddi             #+#    #+#             */
/*   Updated: 2014/05/19 19:56:24 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static unsigned int	space_counter(char const *s, int start, int direction)
{
	unsigned int	count;

	count = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
	{
		count++;
		if (direction > 0)
			start++;
		else
			start--;
	}
	return (count);
}

char				*ft_strtrim(char const *s)
{
	char			*freshtr;
	unsigned int	start;
	unsigned int	len;
	unsigned int	index;

	if (!s)
		return (NULL);
	if (space_counter(s, 0, 1) == ft_strlen(s))
		return (ft_strnew(0));
	start = space_counter(s, 0, 1);
	len = ft_strlen(s) - space_counter(s, ft_strlen(s) - 1, -1) - start;
	freshtr = ft_strnew(len + 1);
	index = 0;
	if (!freshtr)
		return (freshtr);
	while (len--)
		freshtr[index++] = s[start++];
	freshtr[index++] = '\0';
	return (freshtr);
}
