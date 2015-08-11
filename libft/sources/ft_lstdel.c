/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 20:59:31 by aeddi             #+#    #+#             */
/*   Updated: 2014/05/19 19:12:49 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libft_struct.h>
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*alst);
	while (tmp)
	{
		tmp2 = tmp->next;
		(*del)(tmp->content, tmp->content_size);
		free(tmp);
		tmp = tmp2;
	}
	(*alst) = NULL;
}
