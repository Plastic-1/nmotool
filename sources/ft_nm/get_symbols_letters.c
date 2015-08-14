/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_symbols_letters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 14:53:18 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/14 15:34:07 by aeddi            ###   ########.fr       */
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
	else if (!ft_strcmp(sect_name, "__text")
			|| ft_strnstr(sect_name, "__os_", 5)
			|| !ft_strcmp(sect_name, "__gcc_except_tab"))
		return 'T';
	else if (!ft_strcmp(sect_name, "__const")
			|| !ft_strcmp(sect_name, "__ustring")
			|| !ft_strcmp(sect_name, "__cstring")
			|| !ft_strcmp(sect_name, "__interpose")
			|| !ft_strcmp(sect_name, "__crash_info")
			|| ft_strnstr(sect_name, "__objc_", 7)
			|| !ft_strcmp(sect_name, "__common"))
		return 'S';
	else if (!ft_strcmp(sect_name, "__bss"))
		return 'B';
	else if (!ft_strcmp(sect_name, "__data"))
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

ft_putnbr_fd(iter->n_sect - 1, 2);
ft_putchar_fd('\t', 2);
ft_putchar_fd(letter, 2);
ft_putchar_fd('\n', 2);

		iter->letter = letter;
		iter = iter->next;
	}
}
