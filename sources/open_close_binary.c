/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close_binary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 14:43:16 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/12 13:46:34 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <libft.h>
#include <struct.h>

static void	print_file_error(char *filename, char *message)
{
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(message, 2);
}

int			open_binary(char *filename, t_bin *binary)
{
	binary->fd = open(filename, O_RDONLY);
	if (binary->fd > 2)
	{
		if (!fstat(binary->fd, &binary->st))
		{
			binary->data = mmap(0, binary->st.st_size,
								PROT_READ, MAP_PRIVATE, binary->fd, 0);
			if (binary->data != (void *)-1)
				return 0;
			else
				print_file_error(filename, "file maping impossible");
		}
		else
			print_file_error(filename, "file stating impossible");
		close(binary->fd);
	}
	else
		print_file_error(filename, "file openning impossible");
	return 1;
}

int			close_binary(char *filename, t_bin *binary)
{
	if (!munmap(binary->data, binary->st.st_size))
	{
		if (!close(binary->fd))
			return 0;
		else
			print_file_error(filename, "file unmaping impossible");
	}
	else
		print_file_error(filename, "file closing impossible");
	return 1;
}
