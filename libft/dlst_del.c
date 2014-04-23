/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 19:05:09 by aeddi             #+#    #+#             */
/*   Updated: 2013/12/24 14:33:13 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
