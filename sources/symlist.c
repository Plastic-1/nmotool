/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 18:03:20 by aeddi             #+#    #+#             */
/*   Updated: 2014/04/27 16:40:23 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <libft.h>
#include <stdlib.h>
#include <mach-o/nlist.h>
#include <nmotool.h>

t_symlist	*add_sym(char *name, struct nlist *nl32, struct nlist_64 *nl64)
{
	t_symlist	*new;

	new = malloc(sizeof(t_symlist));
	new->name = name;
	new->nl32 = nl32;
	new->nl64 = nl64;
	new->next = NULL;
	return (new);
}

void		free_symlist(t_symlist *root)
{
	t_symlist	*tmp1;
	t_symlist	*tmp2;

	tmp1 = root;
	while (tmp1)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp2);
	}
}

t_symlist	*sort_list32(t_symlist *root)
{
	short			check;
	t_symlist		*tmp1;
	struct nlist	*tmp;
	char			*name;

	check = 1;
	while (check)
	{
		check = 0;
		tmp1 = root;
		while (tmp1->next)
		{
			if (ft_strcmp(tmp1->name, tmp1->next->name) > 0 && ++check)
			{
				tmp = tmp1->nl32;
				name = tmp1->name;
				tmp1->nl32 = tmp1->next->nl32;
				tmp1->name = tmp1->next->name;
				tmp1->next->nl32 = tmp;
				tmp1->next->name = name;
			}
			tmp1 = tmp1->next;
		}
	}
	return (root);
}

t_symlist	*sort_list64(t_symlist *root)
{
	short			check;
	t_symlist		*tmp1;
	struct nlist_64	*tmp;
	char			*name;

	check = 1;
	while (check)
	{
		check = 0;
		tmp1 = root;
		while (tmp1->next)
		{
			if (ft_strcmp(tmp1->name, tmp1->next->name) > 0 && ++check)
			{
				tmp = tmp1->nl64;
				name = tmp1->name;
				tmp1->nl64 = tmp1->next->nl64;
				tmp1->name = tmp1->next->name;
				tmp1->next->nl64 = tmp;
				tmp1->next->name = name;
			}
			tmp1 = tmp1->next;
		}
	}
	return (root);
}

void		print_list(t_symlist *root)
{
	t_symlist	*tmp;
	char		c;

	tmp = root;
	while (tmp)
	{
		if (tmp->nl32)
			c = set_right_sym(tmp->nl32->n_type, tmp->nl32->n_sect);
		else if (tmp->nl64)
			c = set_right_sym(tmp->nl64->n_type, tmp->nl64->n_sect);
		if (tmp->nl32 && tmp->nl32->n_value)
			print_ptr_to_hex(tmp->nl32->n_value, FALSE, FALSE);
		else if (tmp->nl32 && !tmp->nl32->n_value)
			ft_putstr("        ");
		else if (tmp->nl64 && tmp->nl64->n_value)
			print_ptr_to_hex(tmp->nl64->n_value, FALSE, TRUE);
		else if (tmp->nl64 && !tmp->nl64->n_value)
			ft_putstr("                ");
		ft_putchar(' ');
		ft_putchar(c);
		ft_putchar(' ');
		ft_putendl(tmp->name);
		tmp = tmp->next;
	}
}
