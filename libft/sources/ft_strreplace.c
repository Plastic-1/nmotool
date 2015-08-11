/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 12:18:16 by aeddi             #+#    #+#             */
/*   Updated: 2014/05/19 19:50:13 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strreplace(char *s1, char *old, char *new)
{
	int		count;
	char	*cmd_res;
	char	*cmd_ret;

	if ((count = ft_strcount(s1, old)))
	{
		cmd_res = ft_strnew(ft_strlen(s1) + (ft_strlen(new) * count)
							- (ft_strlen(old) * count));
		cmd_ret = cmd_res;
		while (*s1)
		{
			if (ft_strnstr(s1, old, ft_strlen(old)))
			{
				ft_strcpy(cmd_res, new);
				cmd_res += ft_strlen(new);
				s1 += ft_strlen(old);
				continue ;
			}
			*cmd_res = *s1;
			cmd_res++;
			s1++;
		}
		return (cmd_ret);
	}
	return (s1);
}
