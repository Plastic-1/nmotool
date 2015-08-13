/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 17:17:04 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/12 13:31:38 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_struct.h>
#include <libft.h>
#include <stdlib.h>

t_dlst		*dlst_new(void)
{
	t_dlst	*new;

	new = (t_dlst *)malloc(sizeof(t_dlst));
	if (new != NULL)
	{
		new->len = 0;
		new->head = NULL;
		new->tail = NULL;
	}
	return (new);
}
