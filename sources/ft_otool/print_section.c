/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_section.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 16:31:52 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/12 19:09:42 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mach/boolean.h>
#include <libft.h>
#include <nmotool.h>

static void	print_section_name(char *segname, char *sectname)
{
	if (!(!ft_strcmp(segname, "__TEXT") && !ft_strcmp(sectname, "__text")) &&
		!(!ft_strcmp(segname, "__DATA") && !ft_strcmp(sectname, "__data")))
		ft_putstr("Contents of ");
	ft_putchar('(');
	ft_putstr(segname);
	ft_putchar(',');
	ft_putstr(sectname);
	ft_putendl(") section");
}

void		print_section(t_sect *section, char *segname, char *sectname)
{
	size_t	offset;
	short	count;
	char	delim;

	offset = 0;
	print_section_name(segname, sectname);
	if (!ft_strcmp(segname, "__TEXT") && !ft_strcmp(sectname, "__text"))
		delim = ' ';
	else
		delim = '\t';
	while (section->start + offset != section->end)
	{
		count = 0;
		print_ptr_to_hex(section->offset + offset, FALSE, section->len64);
		ft_putchar(delim);
		while (count++ != 16)
		{
			print_byte_to_hex(*(section->start + offset));
			offset++;
			ft_putchar(' ');
			if (section->start + offset == section->end)
				break ;
		}
		ft_putchar('\n');
	}
}
