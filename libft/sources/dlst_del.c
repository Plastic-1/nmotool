/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 19:05:09 by aeddi             #+#    #+#             */
/*   Updated: 2014/05/19 18:58:35 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <libft_struct.h>

void	dlst_del(t_dlst **dl)
{
	t_elem	*tmp;
	t_elem	*del;

	if (*dl != NULL)
	{
		tmp = (*dl)->head;
		while (tmp != NULL)
		{
			del = tmp;
			tmp = tmp->next;
			free(del);
		}
		free(*dl);
		*dl = NULL;
	}
}
