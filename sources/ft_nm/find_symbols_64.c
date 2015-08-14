/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_symbols_64.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 13:57:23 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/14 15:34:37 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <libft.h>
#include <nmotool.h>

static void	get_sect_names(char *sect_names[], struct segment_command_64 *seg)
{
	static size_t		index = 0;
	size_t				count = 0;
	struct section_64	*sec;

	sec = (struct section_64 *)(seg + 1);
	while (count < seg->nsects)
	{
		sect_names[index] = sec->sectname;

ft_putnbr_fd(index, 2);
ft_putchar_fd('\t', 2);
ft_putstr_fd(sec->sectname, 2);
ft_putchar_fd('\n', 2);

		sec++;
		count++;
		index++;
	}
	sect_names[index] = NULL;
}

static void	fill_list(struct symtab_command *sym_t, t_symlist **root, void *ptr)
{
	char						*str_t;
	struct nlist_64				*sym;
	t_symlist					*tmp;
	size_t						i;

	i = -1;
	str_t = (char *)ptr + sym_t->stroff;
	sym = (struct nlist_64 *)((char *)ptr + sym_t->symoff);
	while (++i < sym_t->nsyms)
	{
		if (!(sym[i].n_type & N_STAB))
		{
			if (!*root)
			{
				*root = add_sym(str_t + sym[i].n_un.n_strx, sym + i, 0, FALSE);
				tmp = *root;
			}
			else
			{
				tmp->next = add_sym(str_t + sym[i].n_un.n_strx, sym + i, tmp,
									TRUE);
				tmp = tmp->next;
			}
		}
	}
}

void		find_symbols_64(t_head *headers, t_arg_nm *options)
{
	struct segment_command_64	*seg;
	t_symlist					*root;
	char						*sect_names[256];
	size_t						count;

	count = 0;
	seg = (struct segment_command_64 *)(headers->mach64 + 1);
	root = NULL;
	while (count < headers->mach64->ncmds)
	{
		if (seg->cmd == LC_SEGMENT_64)
			get_sect_names(sect_names, seg);
		if (seg->cmd == LC_SYMTAB)
			fill_list((struct symtab_command *)seg, &root, headers->mach64);
		seg = (struct segment_command_64 *)((char *)seg + seg->cmdsize);
		count++;
	}
	if (root)
	{
		get_symbols_letters(root, sect_names);
		print_list(root, options, TRUE);
		free_symlist(root);
	}
}
