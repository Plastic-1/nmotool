/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_tw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 12:17:52 by aeddi             #+#    #+#             */
/*   Updated: 2014/05/19 19:40:23 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strjoin_tw(const char *s1, const char *s2, const char *s3)
{
	char	*tmp;
	char	*ret;

	if (!s1 || !s2 || !s3)
		return (NULL);
	tmp = ft_strjoin(s1, s2);
	ret = ft_strjoin(tmp, s3);
	ft_strdel(&tmp);
	return (ret);
}
