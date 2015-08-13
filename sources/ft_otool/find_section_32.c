/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_section_32. c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 14:43:16 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/13 05:42:21 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach/boolean.h>
#include <mach-o/loader.h>
#include <libft.h>
#include <nmotool.h>

static void	*get_section_offset_32(char *sectname, void *ptr)
{
	struct segment_command	*seg;
	struct section			*sec;
	size_t					count;

	count = 0;
	if (ptr)
	{
		seg = (struct segment_command *)ptr;
		sec = (struct section *)(seg + 1);
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

static void	*get_segment_offset_32(t_head *headers, char *segname)
{
	struct segment_command	*seg;
	size_t					count;

	count = 0;
	seg = (struct segment_command *)(headers->mach32 + 1);
	while (count < headers->mach32->ncmds)
	{
		if (ft_strcmp(seg->segname, segname) == 0)
			return seg;
		seg = (struct segment_command *)((char *)seg + seg->cmdsize);
		count++;
	}
	return NULL;
}

void		find_section_32(t_head *headers, char *segname, char *sectname)
{
	struct segment_command	*seg;
	struct section			*sec;
	t_sect					section;

	if (headers->mach32->filetype == MH_OBJECT)
		seg = (struct segment_command *)(headers->mach32 + 1);
	else
		seg = get_segment_offset_32(headers, segname);
	sec = (struct section *)get_section_offset_32(sectname, seg);
	if (sec)
	{
		section.start = (char *)headers->mach32 + sec->offset;
		section.end = section.start + sec->size;
		section.offset = sec->addr;
		section.len64 = FALSE;
		print_section(&section, segname, sectname);
	}
}