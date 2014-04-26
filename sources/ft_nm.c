/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 18:03:20 by aeddi             #+#    #+#             */
/*   Updated: 2014/04/23 18:04:11 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <libft.h>
#include <mach-o/fat.h>
#include <mach-o/loader.h>
#include <nmotool.h>

void	fat_filter_big_end(void *ptr, t_text *text)
{
	struct fat_header		*fath;
	struct fat_arch			*fatar;
	struct mach_header_64	*machtmp;
	size_t					i;

	i = 0;
	fath = (struct fat_header *)ptr;
	fatar = (struct fat_arch *)(fath + 1);
	while (i++ < ft_revint32(fath->nfat_arch))
	{
		machtmp = (void *)((char *)ptr + ft_revint32(fatar->offset));
		if (machtmp->magic == MH_MAGIC_64
			&& machtmp->cputype == (cpu_type_t)0x1000007
			&& machtmp->cpusubtype == (cpu_subtype_t)0x80000003)
			text->mach64 = machtmp;
		else if (machtmp->magic == MH_MAGIC
				&& machtmp->cputype == (cpu_type_t)0x0000007
				&& machtmp->cpusubtype == (cpu_subtype_t)0x00000003)
			text->mach32 = (struct mach_header *)machtmp;
		fatar += 1;
	}
}

void	fat_filter_litl_end(void *ptr, t_text *text)
{
	struct fat_header		*fath;
	struct fat_arch			*fatar;
	struct mach_header_64	*machtmp;
	size_t					i;

	i = 0;
	fath = (struct fat_header *)ptr;
	fatar = (struct fat_arch *)(fath + 1);
	while (i++ < fath->nfat_arch)
	{
		machtmp = (void *)((char *)ptr + fatar->offset);
		if (machtmp->magic == MH_MAGIC_64
			&& machtmp->cputype == (cpu_type_t)0x1000007
			&& machtmp->cpusubtype == (cpu_subtype_t)0x80000003)
			text->mach64 = machtmp;
		else if (machtmp->magic == MH_MAGIC
				&& machtmp->cputype == (cpu_type_t)0x0000007
				&& machtmp->cpusubtype == (cpu_subtype_t)0x00000003)
			text->mach32 = (struct mach_header *)machtmp;
		fatar += 1;
	}
}

void	find_simple_header(void *ptr, t_text *text)
{
	struct mach_header_64 *machtmp;

	machtmp = (struct mach_header_64 *)ptr;
	if (machtmp->magic == MH_MAGIC_64
		&& machtmp->cputype == (cpu_type_t)0x1000007
		&& machtmp->cpusubtype == (cpu_subtype_t)0x80000003)
		text->mach64 = machtmp;
	else if (machtmp->magic == MH_MAGIC
		&& machtmp->cputype == (cpu_type_t)0x0000007
		&& machtmp->cpusubtype == (cpu_subtype_t)0x00000003)
		text->mach32 = (struct mach_header *)machtmp;
}

int		ft_nm(void *ptr, char *file)
{
	struct fat_header		*fat;
	t_text					text;

	text.mach64 = NULL;
	text.mach32 = NULL;
	fat = (struct fat_header *)ptr;
	if (fat->magic == FAT_CIGAM)
		fat_filter_big_end(ptr, &text);
	else if (fat->magic == FAT_MAGIC)
		fat_filter_litl_end(ptr, &text);
	else
		find_simple_header(ptr, &text);
	if (text.mach64)
	{
		find_text_sec64(&text, text.mach64);
		display_text_sec64(&text, file);
	}
	else if (text.mach32)
	{
		find_text_sec32(&text, text.mach32);
		display_text_sec32(&text, file);
	}
	else
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	struct stat	s;
	void		*ptr;
	int			fd;

	if (ac != 2)
		return (error_printer("usage ./otool binary", 0));
	if ((fd = open(av[1], O_RDONLY)) < 2)
		return (error_printer("error: file openning impossible", 0));
	fstat(fd, &s);
	if ((ptr = mmap(0, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == (void *)-1)
		return (error_printer("error: file maping impossible", fd));
	if (ft_nm(ptr, av[1]))
	{
		ft_putstr(av[1]);
		ft_putendl(": is not an object file");
	}
	if (munmap(ptr, s.st_size) == -1)
		return (error_printer("error: file unmaping impossible", fd));
	if (close(fd) == -1)
		return (error_printer("error: file closing impossible", 0));
	return (0);
}
