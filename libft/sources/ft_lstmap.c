/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 12:32:30 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/08 15:34:16 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <libft_struct.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh_lst;
	t_list	*tmp;
	t_list	*tmp2;

	fresh_lst = ft_lstnew(lst->content, lst->content_size);
	if (!fresh_lst)
		return (NULL);
	tmp = lst;
	f(fresh_lst);
	if (tmp->next)
	{
		tmp = tmp->next;
		tmp2 = fresh_lst;
	}
	while (tmp)
	{
		tmp2->next = ft_lstnew(tmp->content, tmp->content_size);
		if (!tmp2->next)
			return (NULL);
		tmp = tmp->next;
		f(tmp2->next);
		tmp2 = tmp2->next;
	}
	return (fresh_lst);
}
