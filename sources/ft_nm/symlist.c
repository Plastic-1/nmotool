/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 18:03:20 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/13 05:49:09 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mach-o/nlist.h>
#include <mach-o/loader.h>
#include <nmotool.h>

t_symlist	*add_sym(char *name, void *nlist, t_symlist	*prev, boolean_t len64)
{
	t_symlist		*new;
	struct nlist_64	*sym64;
	struct nlist	*sym32;

	sym64 = (struct nlist_64 *)nlist;
	sym32 = (struct nlist *)nlist;
	new = malloc(sizeof(t_symlist));
	new->name = name;
	if (len64)
	{
		new->n_type = sym64->n_type;
		new->n_sect = sym64->n_sect;
		new->n_value = sym64->n_value;
	}
	else
	{
		new->n_type = sym32->n_type;
		new->n_sect = sym32->n_sect;
		new->n_value = sym32->n_value;
	}
	new->next = NULL;
	new->prev = prev;
	return (new);
}

void		swap_symbols(t_symlist *sym_a, t_symlist *sym_b)
{
	char			*name;
	char			letter;
	uint8_t			n_type;
	uint8_t			n_sect;
	uint64_t		n_value;

	name = sym_a->name;
	letter = sym_a->letter;
	n_type = sym_a->n_type;
	n_sect = sym_a->n_sect;
	n_value = sym_a->n_value;
	sym_a->name = sym_b->name;
	sym_a->letter = sym_b->letter;
	sym_a->n_type = sym_b->n_type;
	sym_a->n_sect = sym_b->n_sect;
	sym_a->n_value = sym_b->n_value;
	sym_b->name = name;
	sym_b->letter = letter;
	sym_b->n_type = n_type;
	sym_b->n_sect = n_sect;
	sym_b->n_value = n_value;
}

t_symlist	*get_tail(t_symlist *iter)
{
	while (iter && iter->next)
		iter = iter->next;
	return iter;
}

void		free_symlist(t_symlist *root)
{
	t_symlist	*iter1;
	t_symlist	*iter2;

	iter1 = root;
	while (iter1)
	{
		iter2 = iter1;
		iter1 = iter1->next;
		free(iter2);
	}
}
