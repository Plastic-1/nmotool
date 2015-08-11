/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 12:24:51 by aeddi             #+#    #+#             */
/*   Updated: 2014/05/19 19:14:22 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libft_struct.h>

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	while (lst)
	{
		(*f)(lst);
		lst = lst->next;
	}
}
