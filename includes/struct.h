/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 15:37:42 by aeddi             #+#    #+#             */
/*   Updated: 2014/04/27 15:38:42 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct				s_sym
{
	struct mach_header_64	*mach64;
	struct mach_header		*mach32;
	struct s_symlist		*root;
}							t_sym;

typedef struct				s_symlist
{
	char					*name;
	struct nlist			*nl32;
	struct nlist_64			*nl64;
	struct s_symlist		*next;
}							t_symlist;

typedef struct				s_text
{
	void					*start;
	void					*end;
	struct mach_header_64	*mach64;
	uint64_t				diff64;
	struct mach_header		*mach32;
	uint32_t				diff32;
}							t_text;

#endif
