/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 13:39:56 by aeddi             #+#    #+#             */
/*   Updated: 2013/12/01 20:42:37 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*freshcat;

	if (!s1 || !s2)
		return (NULL);
	freshcat = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!freshcat)
		return (freshcat);
	freshcat = ft_strcat(freshcat, s1);
	freshcat = ft_strcat(freshcat, s2);
	return (freshcat);
}
