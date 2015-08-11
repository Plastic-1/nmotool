/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 21:41:40 by aeddi             #+#    #+#             */
/*   Updated: 2014/05/19 19:29:35 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	ft_rotup(const char *s, char *temp, int x)
{
	if (*s + x > 'Z')
		*temp = (*s - 26) + x;
	else
		*temp = *s + x;
}

static void	ft_rotdown(const char *s, char *temp, int x)
{
	if (*s + x > 'z')
		*temp = (*s - 26) + x;
	else
		*temp = *s + x;
}

char		*ft_rotx(const char *s, int x, char space)
{
	char	*srot;
	char	*temp;

	srot = ft_strnew(ft_strlen(s));
	temp = srot;
	x %= 26;
	if ((space >= 'A' && space <= 'Z') || (space >= 'a' && space <= 'z'))
		space = '_';
	while (*s)
	{
		if (*s >= 'A' && *s <= 'Z')
			ft_rotup(s, temp, x);
		else if (*s >= 'a' && *s <= 'z')
			ft_rotdown(s, temp, x);
		else if (*s == ' ')
			*temp = space;
		else
			*temp = *s;
		temp++;
		s++;
	}
	return (srot);
}
