/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 18:03:20 by aeddi             #+#    #+#             */
/*   Updated: 2014/04/27 16:36:23 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <nmotool.h>

static void	fill_list32(struct symtab_command *sym, t_symlist **root, void *ptr)
{
	char						*name;
	struct nlist				*el;
	t_symlist					*tmp;
	size_t						i;

	i = 0;
	name = (char *)ptr + sym->stroff;
	el = (struct nlist *)((char *)ptr + sym->symoff);
	while (i++ < sym->nsyms)
	{
		if (!(el[i].n_type & N_STAB))
		{
			if (!*root)
			{
				*root = add_sym(name + el[i].n_un.n_strx, el + i, NULL);
				tmp = *root;
			}
			else
			{
				tmp->next = add_sym(name + el[i].n_un.n_strx,
									el + i, NULL);
				tmp = tmp->next;
			}
		}
	}
}

void		find_print_symbol32(t_text *text)
{
	struct segment_command	*seg;
	struct symtab_command	*sym;
	t_symlist				*root;
	size_t					i;

	i = 0;
	seg = (struct segment_command *)(text->mach32 + 1);
	root = NULL;
	while (i++ < text->mach32->ncmds)
	{
		if (seg->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)seg;
			fill_list32(sym, &root, text->mach32);
			root = sort_list32(root);
			print_list(root);
			free_symlist(root);
		}
		seg = (struct segment_command *)((char *)seg + seg->cmdsize);
	}
}

static void	fill_list64(struct symtab_command *sym, t_symlist **root, void *ptr)
{
	char						*name;
	struct nlist_64				*el;
	t_symlist					*tmp;
	size_t						i;

	i = 0;
	name = (char *)ptr + sym->stroff;
	el = (struct nlist_64 *)((char *)ptr + sym->symoff);
	while (i++ < sym->nsyms)
	{
		if (!(el[i].n_type & N_STAB))
		{
			if (!*root)
			{
				*root = add_sym(name + el[i].n_un.n_strx, NULL, el + i);
				tmp = *root;
			}
			else
			{
				tmp->next = add_sym(name + el[i].n_un.n_strx,
									NULL, el + i);
				tmp = tmp->next;
			}
		}
	}
}

void		find_print_symbol64(t_text *text)
{
	struct segment_command_64	*seg;
	struct symtab_command		*sym;
	t_symlist					*root;
	size_t						i;

	i = 0;
	seg = (struct segment_command_64 *)(text->mach64 + 1);
	root = NULL;
	while (i++ < text->mach64->ncmds)
	{
		if (seg->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)seg;
			fill_list64(sym, &root, text->mach64);
			root = sort_list64(root);
			print_list(root);
			free_symlist(root);
		}
		seg = (struct segment_command_64 *)((char *)seg + seg->cmdsize);
	}
}

char		set_right_sym(uint8_t n_type, uint16_t n_sect)
{
	char ret;

	ret = ' ';
	if ((n_type & N_TYPE) == N_UNDF)
		ret = 'U';
	else if ((n_type & N_TYPE) == N_ABS)
		ret = 'A';
	else if (n_sect == 1)
		ret = 'T';
	else if (n_sect == 5 || n_sect == 23 || n_sect == 25 || n_sect == 27)
		ret = 'S';
	else if (n_sect == 9 || n_sect == 28)
		ret = 'B';
	else if (n_sect == 8 || n_sect == 24)
		ret = 'D';
	else
		ft_putnbr(n_sect);
	if (!(n_type & N_EXT) && ret != ' ')
		ret += 32;
	return (ret);
}
