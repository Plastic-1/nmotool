/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 14:43:16 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/11 14:19:35 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <libft.h>
#include <mach-o/fat.h>
#include <mach-o/loader.h>
#include <nmotool.h>

		#include <stdio.h>

static void	get_fat_binary_headers(void *ptr, t_text *text)
{
	struct fat_header		*fat_h;
	struct fat_arch			*fat_ar;
	struct mach_header_64	*machtmp;
	size_t					i;

	i = 0;
	fat_h = (struct fat_header *)ptr;
	fat_ar = (struct fat_arch *)(fat_h + 1);
	while (i++ < ft_revint32(fat_h->nfat_arch))
	{
		machtmp = (void *)((char *)ptr + ft_revint32(fat_ar->offset));
		if (machtmp->magic == MH_MAGIC_64)
			text->mach64 = machtmp;
		else if (machtmp->magic == MH_MAGIC)
			text->mach32 = (struct mach_header *)machtmp;
		fat_ar += 1;
	}
}

static void	get_simple_binary_header(void *ptr, t_text *text)
{
	struct mach_header_64 *machtmp;

	machtmp = (struct mach_header_64 *)ptr;
	if (machtmp->magic == MH_MAGIC_64)
		text->mach64 = machtmp;
	else if (machtmp->magic == MH_MAGIC)
		text->mach32 = (struct mach_header *)machtmp;
}

void		get_binary_headers(void *ptr, t_text *text)
{
	struct fat_header		*fat_h;

	text->mach64 = NULL;
	text->mach32 = NULL;
	fat_h = (struct fat_header *)ptr;
	if (fat_h->magic == FAT_CIGAM)
{
printf("FAT\n");
		get_fat_binary_headers(ptr, text);
}
	else
{
printf("SIMPLE\n");
		get_simple_binary_header(ptr, text);
}
}

int		ft_otool(void *ptr, char *file)
{
	t_text					text;

	get_binary_headers(ptr, &text);
	if (text.mach64)
	{
printf("64\n");
(void)file;
		/* find_text_sec64(&text, text.mach64); */
		/* display_text_sec64(&text, file); */
	}
	if (text.mach32)
	{
(void)file;
printf("32\n");
		/* find_text_sec32(&text, text.mach32); */
		/* display_text_sec32(&text, file); */
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
		return (error_printer("usage ./ft_otool binary", 0));
	if ((fd = open(av[1], O_RDONLY)) < 2)
		return (error_printer("error: file openning impossible", 0));
	fstat(fd, &s);
	if ((ptr = mmap(0, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == (void *)-1)
		return (error_printer("error: file maping impossible", fd));
	if (ft_otool(ptr, av[1]))
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
