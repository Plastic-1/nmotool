/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_add_tail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 18:29:27 by aeddi             #+#    #+#             */
/*   Updated: 2013/12/22 09:33:26 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlst			*dlst_add_tail(t_dlst *dl, long int ind, void *cont)
{
	t_elem	*new;

	if (dl != NULL)
	{
		new = (t_elem *)malloc(sizeof(t_elem));
		if (new != NULL && ++dl->len)
		{
			new->ind = ind;
			new->cont = cont;
			new->next = NULL;
			if (dl->tail == NULL)
			{
				new->prev = NULL;
				dl->head = new;
				dl->tail = new;
			}
			else
			{
				dl->tail->next = new;
				new->prev = dl->tail;
				dl->tail = new;
			}
		}
	}
	return (dl);
}
