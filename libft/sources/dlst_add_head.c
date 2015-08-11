/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_add_head.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 17:58:40 by aeddi             #+#    #+#             */
/*   Updated: 2014/05/19 20:01:22 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <libft_struct.h>

t_dlst		*dlst_add_head(t_dlst *dl, long int ind, void *cont)
{
	t_elem	*new;

	if (dl != NULL)
	{
		new = (t_elem *)malloc(sizeof(t_elem));
		if (new != NULL && ++dl->len)
		{
			new->ind = ind;
			new->cont = cont;
			new->prev = NULL;
			if (dl->tail == NULL)
			{
				new->next = NULL;
				dl->head = new;
				dl->tail = new;
			}
			else
			{
				dl->head->prev = new;
				new->next = dl->head;
				dl->head = new;
			}
		}
	}
	return (dl);
}
