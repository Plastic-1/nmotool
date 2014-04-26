/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool_aux32.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 14:43:16 by aeddi             #+#    #+#             */
/*   Updated: 2014/04/25 18:09:41 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <mach-o/loader.h>
#include <nmotool.h>

void	display_text_sec32(t_text *text, char *file)
{
	size_t	total;
	short	count;

	ft_putstr(file);
	ft_putstr(":\n");
	ft_putendl("(__TEXT,__text) section");
	total = 0;
	while ((char *)text->start + total != (char *)text->end)
	{
		count = 0;
		print_ptr_to_hex(text->diff32 + total, FALSE, FALSE);
		ft_putchar(' ');
		while (count++ != 16)
		{
			print_byte_to_hex(*(unsigned char *)((char *)text->start + total));
			total++;
			ft_putchar(' ');
			if ((char *)text->start + total == (char *)text->end)
				break ;
		}
		ft_putchar('\n');
	}
}

void	find_text_sec32(t_text *text, struct mach_header *mach)
{
	struct segment_command	*seg;
	struct section			*sec;
	size_t					i;

	i = 0;
	seg = (struct segment_command *)(mach + 1);
	while (i++ < mach->ncmds)
	{
		if (ft_strcmp(seg->segname, "__TEXT") == 0)
		{
			i = 0;
			sec = (struct section *)(seg + 1);
			while (i++ < seg->nsects)
			{
				if (ft_strcmp(sec->sectname, "__text") == 0)
				{
					text->start = (char *)mach + sec->offset;
					text->end = (char *)text->start + sec->size;
					text->diff32 = sec->addr;
				}
				sec += 1;
			}
		}
		seg = (struct segment_command *)((char *)seg + seg->cmdsize);
	}
}
