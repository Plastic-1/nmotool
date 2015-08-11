/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:01:44 by aeddi             #+#    #+#             */
/*   Updated: 2014/05/19 19:16:54 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*fresh;

	fresh = malloc(size * sizeof(char));
	ft_bzero(fresh, size);
	return (fresh);
}
