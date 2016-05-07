/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_section_64.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 18:01:26 by aeddi             #+#    #+#             */
/*   Updated: 2016/05/07 14:40:50 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach/boolean.h>
#include <mach-o/loader.h>
#include <libft.h>
#include <nmotool.h>

static void	*get_section_offset_64(char *sectname, void *ptr)
{
	struct segment_command_64	*seg;
	struct section_64			*sec;
	size_t						count;

	count = 0;
	if (ptr)
	{
		seg = (struct segment_command_64 *)ptr;
		sec = (struct section_64 *)(seg + 1);
		while (count < seg->nsects)
		{
			if (ft_strcmp(sec->sectname, sectname) == 0)
				return (sec);
			sec += 1;
			count++;
		}
	}
	return (NULL);
}

static void	*get_segment_offset_64(t_head *headers, char *segname)
{
	struct segment_command_64	*seg;
	size_t						count;

	count = 0;
	seg = (struct segment_command_64 *)(headers->mach64 + 1);
	while (count < headers->mach64->ncmds)
	{
		if (ft_strcmp(seg->segname, segname) == 0)
			return (seg);
		seg = (struct segment_command_64 *)((char *)seg + seg->cmdsize);
		count++;
	}
	return (NULL);
}

void		find_section_64(t_head *head, char *seg_n, char *sect_n, int cust)
{
	struct segment_command_64	*seg_l;
	struct section_64			*sec_l;
	t_sect						section;

	if (head->mach64->filetype == MH_OBJECT)
		seg_l = (struct segment_command_64 *)(head->mach64 + 1);
	else
		seg_l = get_segment_offset_64(head, seg_n);
	sec_l = (struct section_64 *)get_section_offset_64(sect_n, seg_l);
	if (sec_l)
	{
		section.start = (char *)head->mach64 + sec_l->offset;
		section.end = section.start + sec_l->size;
		section.offset = sec_l->addr;
		section.len64 = TRUE;
		print_section(&section, seg_n, sect_n, cust);
	}
}
