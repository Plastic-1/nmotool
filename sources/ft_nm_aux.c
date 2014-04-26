/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm_aux32.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 18:03:20 by aeddi             #+#    #+#             */
/*   Updated: 2014/04/23 18:04:11 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <nmotool.h>

void	find_print_symbol32(t_text *text, struct mach_header *mach)
{
	struct segment_command	*seg;
	struct symtab_command	*sym;
	struct nlist			*elem;
	char					*sym_name;
	size_t					i;

(void)text;
	i = 0;
	seg = (struct segment_command *)(mach + 1);
	while (i++ < mach->ncmds)
	{
		if (seg->cmd == LC_SYMTAB)
		{
			i = 0;
			sym = (struct symtab_command *)seg;
			sym_name = (char *)mach + sym->stroff;
			elem = (struct nlist *)((char *)mach + sym->symoff);
			while (i++ < sym->nsyms)
			{
				if ((elem[i].n_type & N_TYPE) == N_UNDF)
					ft_putstr("U ");
				else if ((elem[i].n_type & N_TYPE) == N_ABS)
					ft_putstr("T ");
				else if (!(elem[i].n_type & N_STAB))
					ft_putstr("T ");
				if (!(elem[i].n_type & N_STAB))
					ft_putendl(sym_name + elem[i].n_un.n_strx);
				/*
				ft_putendl("=========================================");
				ft_putendl(sym_name + elem[i].n_un.n_strx);
				ft_putendl("=========================================");
				ft_putchar(elem[i].n_type);
				ft_putchar('\n');
				ft_putchar(elem[i].n_sect);
				ft_putchar('\n');
				ft_putnbr(elem[i].n_desc);
				ft_putchar('\n');
				ft_putnbr(elem[i].n_value);
				ft_putchar('\n');
				*/
			}
		}
		seg = (struct segment_command *)((char *)seg + seg->cmdsize);
	}
}

void	find_print_symbol64(t_text *text, struct mach_header_64 *mach)
{
	struct segment_command_64	*seg;
	struct symtab_command		*sym;
	struct nlist_64				*elem;
	char						*sym_name;
	size_t						i;

(void)text;
	i = 0;
	seg = (struct segment_command_64 *)(mach + 1);
	while (i++ < mach->ncmds)
	{
		if (seg->cmd == LC_SYMTAB)
		{
			i = 0;
			sym = (struct symtab_command *)seg;
			sym_name = (char *)mach + sym->stroff;
			elem = (struct nlist_64 *)((char *)mach + sym->symoff);
			while (i++ < sym->nsyms)
			{
				if ((elem[i].n_type & N_TYPE) == N_UNDF)
					ft_putstr("U ");
				else if ((elem[i].n_type & N_TYPE) == N_ABS)
					ft_putstr("T ");
				else if (!(elem[i].n_type & N_STAB))
					ft_putstr("T ");
				if (!(elem[i].n_type & N_STAB))
					ft_putendl(sym_name + elem[i].n_un.n_strx);
				/*
				ft_putendl("=========================================");
				ft_putendl(sym_name + elem[i].n_un.n_strx);
				ft_putendl("=========================================");
				ft_putchar(elem[i].n_type);
				ft_putchar('\n');
				ft_putchar(elem[i].n_sect);
				ft_putchar('\n');
				ft_putnbr(elem[i].n_desc);
				ft_putchar('\n');
				ft_putnbr(elem[i].n_value);
				ft_putchar('\n');
				*/
			}
		}
		seg = (struct segment_command_64 *)((char *)seg + seg->cmdsize);
	}
}
