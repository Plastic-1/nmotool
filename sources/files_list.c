/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 14:43:16 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/18 17:43:57 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <struct.h>
#include <stdlib.h>

void			files_list_add(t_filelst **lst, char *filename)
{
	t_filelst	*add;
	t_filelst	*iter;

	add = (t_filelst *)malloc(sizeof(t_filelst));
	add->name = filename;
	add->next = NULL;
	if (*lst == NULL)
		*lst = add;
	else
	{
		iter = *lst;
		while (iter->next)
			iter = iter->next;
		iter->next = add;
	}
}

void			files_list_del(t_filelst **lst)
{
	t_filelst	*iter;
	t_filelst	*pop;

	iter = *lst;
	while (iter)
	{
		pop = iter;
		iter = iter->next;
		free(pop);
	}
	*lst = NULL;
}

unsigned int	files_list_count(t_filelst *lst)
{
	unsigned int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
