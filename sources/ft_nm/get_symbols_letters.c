/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_symbols_letters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 14:53:18 by aeddi             #+#    #+#             */
/*   Updated: 2016/05/07 15:24:21 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/nlist.h>
#include <libft.h>
#include <nmotool.h>

static char	match_not_s_letter_sect(char *sect_name)
{
	if (ft_strnstr(sect_name, "__text", 6)
			|| ft_strnstr(sect_name, "__os_", 5))
		return ('T');
	else if (ft_strnstr(sect_name, "__bss", 5))
		return ('B');
	else if (ft_strnstr(sect_name, "__data", 6))
		return ('D');
	return (' ');
}

static char	match_letter_sect(char *sect_name)
{
	if (ft_strnstr(sect_name, "__const", 7)
			|| ft_strnstr(sect_name, "__gcc_except_tab", 16)
			|| ft_strnstr(sect_name, "__ustring", 9)
			|| ft_strnstr(sect_name, "__cstring", 9)
			|| ft_strnstr(sect_name, "__interpose", 11)
			|| ft_strnstr(sect_name, "__crash_info", 12)
			|| ft_strnstr(sect_name, "__objc_", 7)
			|| ft_strnstr(sect_name, "__xcrun_shim", 12)
			|| ft_strnstr(sect_name, "__common", 8)
			|| ft_strnstr(sect_name, "__dyld", 6)
			|| ft_strnstr(sect_name, "__class", 7)
			|| ft_strnstr(sect_name, "__eh_frame", 10)
			|| ft_strnstr(sect_name, "__program_vars", 14)
			|| ft_strnstr(sect_name, "__all_image_info", 16)
			|| ft_strnstr(sect_name, "__textcoal_nt", 13)
			|| ft_strnstr(sect_name, "__os_activity", 13)
			|| ft_strnstr(sect_name, "__os_log", 8)
			|| ft_strnstr(sect_name, "__os_trace", 10))
		return ('S');
	else
		return (match_not_s_letter_sect(sect_name));
}

void		get_symbols_letters(t_symlist *root, char *sect_names[])
{
	t_symlist	*iter;
	char		letter;

	iter = root;
	while (iter)
	{
		if ((iter->n_type & N_TYPE) == N_UNDF)
			letter = 'U';
		else if ((iter->n_type & N_TYPE) == N_INDR)
			letter = 'I';
		else if ((iter->n_type & N_TYPE) == N_ABS)
			letter = 'A';
		else if (iter->n_sect == NO_SECT
			|| iter->n_sect > MAX_SECT
			|| sect_names[iter->n_sect - 1] == NULL)
			letter = ' ';
		else
			letter = match_letter_sect(sect_names[iter->n_sect - 1]);
		if (!(iter->n_type & N_EXT) && letter != ' ')
			letter += 32;
		iter->letter = letter;
		iter = iter->next;
	}
}
