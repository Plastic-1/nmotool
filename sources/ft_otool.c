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

size_t	size_of_file(int fd)
{
	struct stat	stat;

	fstat(fd, &stat);
	return (stat.st_size);
}

int		ft_otool(void *ptr, size_t size)
{
	struct fat_header		*fat;
	struct mach_header_64	*mach;
	size_t					size;

	size = 0;
	fat = (struct fat_header *)ptr;
	if (fat->magic == FAT_MAGIC)
	{
		ft_putendl("Is a fat binary - Big endian");
		size = fat->size
	}
	if (fat->magic == FAT_CIGAM)
	{
		ft_putendl("Is a fat binary - Little endian");
	}
	mach = (struct mach_header_64 *)ptr;
	if (mach->magic == MH_MAGIC_64)
	{
		ft_putendl("Is a binary - Big endian");
	}
	if (mach->magic == MH_CIGAM_64)
	{
		ft_putendl("Is a binary - Little endian");
	}
	(void)size;
	return (0);
}

int		main(int ac, char **av)
{
	void	*ptr;
	size_t	size;
	int		ret;
	int		fd;

ret = 0;
	if (ac != 2)
		return (error_printer("usage ./otool binary", 0));
	if ((fd = open(av[1], O_RDONLY)) < 2)
		return (error_printer("error: file openning impossible", 0));
	size = size_of_file(fd);
	if ((ptr = mmap(0, size, PROT_READ, MAP_SHARED, fd, 0)) == (void *)-1)
		return (error_printer("error: file maping impossible", fd));
	ft_otool(ptr, size);
	if (munmap(ptr, size) == -1)
		return (error_printer("error: file unmaping impossible", fd));
	if (close(fd) == -1)
		return (error_printer("error: file closing impossible", 0));
	return (ret);
}
