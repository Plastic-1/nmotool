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

void	display_text_section(t_text *text)
{
	(void)text;
}

void	find_text_section(t_text *text, struct mach_header_64 *mach)
{
	(void)text;
	ft_putstr("Found : ");
	print_ptr_to_hex((size_t)mach, TRUE, FALSE);
	ft_putstr("\n");
}

int		ft_otool(void *ptr)
{
	struct fat_header		*fath;
	struct fat_arch			*fatar;
	struct mach_header_64	*mach;
	size_t					i;
	t_text					text;

	i = 0;
	text.start = NULL;
	fath = (struct fat_header *)ptr;
	mach = (struct mach_header_64 *)ptr;
	if (fath->magic == FAT_CIGAM)
	{
		fatar = (struct fat_arch *)(fath + 1);
		while (i++ < ft_revint32(fath->nfat_arch))
		{
			mach = (void *)((char *)ptr + ft_revint32(fatar->offset));
			if (mach->magic == MH_MAGIC_64)
				find_text_section(&text, mach);
			fatar += 1;
		}
	}
	else if (mach->magic == MH_MAGIC_64)
		find_text_section(&text, mach);
	display_text_section(&text);
	return (0);
}

int		main(int ac, char **av)
{
	struct stat	stat;
	void		*ptr;
	int			ret;
	int			fd;

ret = 0;
	if (ac != 2)
		return (error_printer("usage ./otool binary", 0));
	if ((fd = open(av[1], O_RDONLY)) < 2)
		return (error_printer("error: file openning impossible", 0));
	fstat(fd, &stat);
	if ((ptr = mmap(0, stat.st_size, PROT_READ, MAP_SHARED, fd, 0)) == (void *)-1)
		return (error_printer("error: file maping impossible", fd));
	ft_otool(ptr);
	if (munmap(ptr, stat.st_size) == -1)
		return (error_printer("error: file unmaping impossible", fd));
	if (close(fd) == -1)
		return (error_printer("error: file closing impossible", 0));
	return (ret);
}
