/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_symbols_letters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 14:53:18 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/15 14:19:56 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/nlist.h>
#include <libft.h>
#include <nmotool.h>

static char	match_letter_sect(char *sect_name, uint8_t n_type)
{
	if ((n_type & N_TYPE) == N_UNDF)
		return 'U';
	else if ((n_type & N_TYPE) == N_ABS)
		return 'A';
	else if (ft_strnstr(sect_name, "__text", 6)
			|| ft_strnstr(sect_name, "__os_", 5))
		return 'T';
	else if (ft_strnstr(sect_name, "__const", 7)
			|| ft_strnstr(sect_name, "__gcc_except_tab", 16)
			|| ft_strnstr(sect_name, "__ustring", 9)
			|| ft_strnstr(sect_name, "__cstring", 9)
			|| ft_strnstr(sect_name, "__interpose", 11)
			|| ft_strnstr(sect_name, "__crash_info", 12)
			|| ft_strnstr(sect_name, "__objc_", 7)
			|| ft_strnstr(sect_name, "__common", 8))
		return 'S';
	else if (ft_strnstr(sect_name, "__bss", 5))
		return 'B';
	else if (ft_strnstr(sect_name, "__data", 6))
		return 'D';
	else
		return ' ';
}

void		get_symbols_letters(t_symlist *root, char *sect_names[])
{
	t_symlist	*iter;
	char		letter;

	iter = root;
	while (iter)
	{
		letter = match_letter_sect(sect_names[iter->n_sect - 1], iter->n_type);
		if (!(iter->n_type & N_EXT) && letter != ' ')
			letter += 32;
		iter->letter = letter;
		iter = iter->next;
	}
}
