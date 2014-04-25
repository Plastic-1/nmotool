/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 14:43:16 by aeddi             #+#    #+#             */
/*   Updated: 2014/04/25 18:09:41 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/mman.h>
#include <libft.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <mach-o/fat.h>
#include <mach-o/loader.h>
#include <nmotool.h>

int		error_printer(char *str, int fd)
{
	ft_putendl(str);
	if (fd && close(fd) == -1)
		ft_putendl("error: file closing impossible");
	return (1);
}

void	display_text_sec(t_text *text, char *file)
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
		print_ptr_to_hex(text->diff + total, FALSE, TRUE);
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

void	find_text_sec(t_text *text, struct mach_header_64 *mach)
{
	struct segment_command_64	*seg;
	struct section_64			*sec;
	size_t						i;

	i = 0;
	seg = (struct segment_command_64 *)(mach + 1);
	while (i++ < mach->ncmds)
	{
		if (ft_strcmp(seg->segname, "__TEXT") == 0)
		{
			i = 0;
			sec = (struct section_64 *)(seg + 1);
			while (i++ < seg->nsects)
			{
				if (ft_strcmp(sec->sectname, "__text") == 0)
				{
					text->start = (char *)mach + sec->offset;
					text->end = (char *)text->start + sec->size;
					text->diff = sec->addr;
				}
				sec += 1;
			}
		}
		seg = (struct segment_command_64 *)((char *)seg + seg->cmdsize);
	}
}

struct mach_header_64	*fat_filter_big_end(void *ptr)
{
	struct fat_header		*fath;
	struct fat_arch			*fatar;
	struct mach_header_64	*mach;
	size_t					i;

	i = 0;
	fath = (struct fat_header *)ptr;
	fatar = (struct fat_arch *)(fath + 1);
	while (i++ < ft_revint32(fath->nfat_arch))
	{
		mach = (void *)((char *)ptr + ft_revint32(fatar->offset));
		if (mach->magic == MH_MAGIC_64
			&& fatar->cputype == (cpu_type_t)0x7000001
			&& fatar->cpusubtype == (cpu_type_t)0x3000080)
			return (mach);
		fatar += 1;
	}
	return (NULL);
}

struct mach_header_64	*fat_filter_litl_end(void *ptr)
{
	struct fat_header		*fath;
	struct fat_arch			*fatar;
	struct mach_header_64	*mach;
	size_t					i;

	i = 0;
	fath = (struct fat_header *)ptr;
	fatar = (struct fat_arch *)(fath + 1);
	while (i++ < fath->nfat_arch)
	{
		mach = (void *)((char *)ptr + fatar->offset);
		if (mach->magic == MH_MAGIC_64
			&& mach->cputype == (cpu_type_t)0x1000007
			&& mach->cpusubtype == (cpu_subtype_t)0x80000003)
			return (mach);
		fatar += 1;
	}
	return (NULL);
}

int		ft_otool(void *ptr, char *file)
{
	struct fat_header		*fat;
	struct mach_header_64	*mach;
	t_text					text;

	fat = (struct fat_header *)ptr;
	mach = (struct mach_header_64 *)ptr;
	if (fat->magic == FAT_CIGAM)
		mach = fat_filter_big_end(ptr);
	else if (fat->magic == FAT_MAGIC)
		mach = fat_filter_litl_end(ptr);
	else if (mach->magic != MH_MAGIC_64
			|| mach->cputype != (cpu_type_t)0x1000007
			|| mach->cpusubtype != (cpu_subtype_t)0x80000003)
		mach = NULL;
	if (mach)
	{
		find_text_sec(&text, mach);
		display_text_sec(&text, file);
	}
	return (0);
}

int		main(int ac, char **av)
{
	struct stat	s;
	void		*ptr;
	int			ret;
	int			fd;

ret = 0;
	if (ac != 2)
		return (error_printer("usage ./otool binary", 0));
	if ((fd = open(av[1], O_RDONLY)) < 2)
		return (error_printer("error: file openning impossible", 0));
	fstat(fd, &s);
	if ((ptr = mmap(0, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == (void *)-1)
		return (error_printer("error: file maping impossible", fd));
	ft_otool(ptr, av[1]);
	if (munmap(ptr, s.st_size) == -1)
		return (error_printer("error: file unmaping impossible", fd));
	if (close(fd) == -1)
		return (error_printer("error: file closing impossible", 0));
	return (ret);
}
