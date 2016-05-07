/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_section.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 16:31:52 by aeddi             #+#    #+#             */
/*   Updated: 2016/05/07 14:32:24 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mach/boolean.h>
#include <libft.h>
#include <nmotool.h>

static void	print_section_name(char *segname, char *sectname, int custom)
{
	if (custom)
		ft_putstr("Contents of ");
	ft_putchar('(');
	ft_putstr(segname);
	ft_putchar(',');
	ft_putstr(sectname);
	ft_putendl(") section");
}

void		print_section(t_sect *section, char *seg, char *sect, int cust)
{
	size_t	offset;
	short	count;
	char	delim;

	offset = 0;
	print_section_name(seg, sect, cust);
	if (!ft_strcmp(seg, "__TEXT") && !ft_strcmp(sect, "__text"))
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
