/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_section_32.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 18:10:54 by aeddi             #+#    #+#             */
/*   Updated: 2016/05/07 14:40:36 by aeddi            ###   ########.fr       */
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
				return (sec);
			sec += 1;
			count++;
		}
	}
	return (NULL);
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
			return (seg);
		seg = (struct segment_command *)((char *)seg + seg->cmdsize);
		count++;
	}
	return (NULL);
}

void		find_section_32(t_head *head, char *seg_n, char *sect_n, int cust)
{
	struct segment_command	*seg_l;
	struct section			*sec_l;
	t_sect					sect;

	if (head->mach32->filetype == MH_OBJECT)
		seg_l = (struct segment_command *)(head->mach32 + 1);
	else
		seg_l = get_segment_offset_32(head, seg_n);
	sec_l = (struct section *)get_section_offset_32(sect_n, seg_l);
	if (sec_l)
	{
		sect.start = (char *)head->mach32 + sec_l->offset;
		sect.end = sect.start + sec_l->size;
		sect.offset = sec_l->addr;
		sect.len64 = FALSE;
		print_section(&sect, seg_n, sect_n, cust);
	}
}
