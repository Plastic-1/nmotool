/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 17:34:09 by aeddi             #+#    #+#             */
/*   Updated: 2013/12/22 22:03:43 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*fresh;

	fresh = (t_list *)ft_memalloc(sizeof(t_list));
	if (!fresh)
		return (NULL);
	else if (!content)
	{
		fresh->content = NULL;
		fresh->content_size = 0;
	}
	else
	{
		fresh->content = (void *)content;
		fresh->content_size = content_size;
	}
	fresh->next = NULL;
	return (fresh);
}
