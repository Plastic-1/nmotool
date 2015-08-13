/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_section_64.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 09:28:33 by plastic           #+#    #+#             */
/*   Updated: 2015/08/12 17:07:02 by plastic          ###   ########.fr       */
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
				return sec;
			sec += 1;
			count++;
		}
	}
	return NULL;
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
			return seg;
		seg = (struct segment_command_64 *)((char *)seg + seg->cmdsize);
		count++;
	}
	return NULL;
}

void		find_section_64(t_head *headers, char *segname, char *sectname)
{
	struct segment_command_64	*seg;
	struct section_64			*sec;
	t_sect						section;

	if (headers->mach64->filetype == MH_OBJECT)
		seg = (struct segment_command_64 *)(headers->mach64 + 1);
	else
		seg = get_segment_offset_64(headers, segname);
	sec = (struct section_64 *)get_section_offset_64(sectname, seg);
	if (sec)
	{
		section.start = (char *)headers->mach64 + sec->offset;
		section.end = section.start + sec->size;
		section.offset = sec->addr;
		section.len64 = TRUE;
		print_section(&section, segname, sectname);
	}
}
