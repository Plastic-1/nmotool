/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 14:43:16 by aeddi             #+#    #+#             */
/*   Updated: 2014/04/23 19:39:54 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/mman.h>
#include <libft.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <mach-o/fat.h>
#include <mach-o/loader.h>

int		error_printer(char *str, int fd)
{
	ft_putendl(str);
	if (fd && close(fd) == -1)
		ft_putendl("error: file closing impossible");
	return (1);
}

int		ft_otool(void *ptr, size_t size)
{
	struct fat_header		*fat;
	struct mach_header_64	*mach;
	t_bin					*list;

	fat = (struct fat_header *)ptr;
	mach = (struct mach_header_64 *)ptr;
	if (fat->magic == FAT_CIGAM)
	{
		add_header();
	}
	else if (mach->magic == MH_CIGAM_64)

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
	ft_otool(ptr, stat.st_size);
	if (munmap(ptr, stat.st_size) == -1)
		return (error_printer("error: file unmaping impossible", fd));
	if (close(fd) == -1)
		return (error_printer("error: file closing impossible", 0));
	return (ret);
}
