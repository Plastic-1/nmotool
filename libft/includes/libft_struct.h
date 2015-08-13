/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 14:34:26 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/12 13:30:50 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRUCT_H
# define LIBFT_STRUCT_H

# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_elem
{
	long int		ind;
	void			*cont;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

typedef struct		s_dlst
{
	size_t			len;
	t_elem			*head;
	t_elem			*tail;
}					t_dlst;

#endif
