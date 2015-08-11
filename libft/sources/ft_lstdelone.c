/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 19:14:08 by aeddi             #+#    #+#             */
/*   Updated: 2014/05/19 19:13:17 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <libft_struct.h>

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	(*del)((*alst)->content, (*alst)->content_size);
	ft_memdel((void **)alst);
}
