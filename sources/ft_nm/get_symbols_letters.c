/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_symbols_letters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 14:53:18 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/13 06:10:46 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/nlist.h>
#include <libft.h>
#include <nmotool.h>

static char	match_letter_sect_name(char *sect_name, uint8_t n_type)
{
	if ((n_type & N_TYPE) == N_UNDF)
		return 'U';
	else if ((n_type & N_TYPE) == N_ABS)
		return 'A';
	else if (!ft_strcmp(sect_name, "__text"))
		return 'T';
	else if (!ft_strcmp(sect_name, "ZIB"))
		return 'S';
	else if (!ft_strcmp(sect_name, "ZOB"))
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
		letter = match_letter_sect_name(sect_names[iter->n_sect], iter->n_type);
		if (!(iter->n_type & N_EXT) && letter != ' ')
			letter += 32;
		iter->letter = letter;
		iter = iter->next;
	}
}
