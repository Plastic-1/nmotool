/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 18:03:20 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/13 04:14:18 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <struct.h>
#include <nmotool.h>

static void	print_filename_arch(char *filename, char *arch)
{
	ft_putchar('\n');
	ft_putstr(filename);
	if (arch)
		ft_putstr(arch);
	ft_putendl(":");
}

static void	print_symbols(char *filename, t_arg_nm *options, t_head *headers)
{
	if (headers->mach64 && (options->arch == A_ALL
		|| options->arch == A_DEF || options->arch == A_X64))
	{
		if (options->arch == A_ALL && headers->mach32)
			print_filename_arch(filename, " (for architecture x86_64)");
		find_symbols_64(headers, options);
	}
	if (headers->mach32 && (options->arch == A_ALL || options->arch == A_X32))
	{
		if (options->arch == A_ALL)
			print_filename_arch(filename, " (for architecture i386)");
		find_symbols_32(headers, options);
	}
}

static int	nm(char *filename, t_arg_nm *options, t_bin *binary)
{
	t_head	headers;

	get_binary_headers(binary->data, &headers);
	if (!headers.mach32 && !headers.mach64)
	{
		ft_putstr(filename);
		ft_putstr(": ");
		ft_putendl("is not an object file");
		return 1;
	}
	print_symbols(filename, options, &headers);
	return 0;
}

int			main(int ac, char **av)
{
	t_bin			binary;
	t_arg_nm		options;
	t_filelst		*file;

	if (get_args_nm(ac, av, &options))
		return 1;
	file = options.files;
	while (file)
	{
		if (open_binary(file->name, &binary))
			return 2;
		if (nm(file->name, &options, &binary))
			return 3;
		if (close_binary(file->name, &binary))
			return 4;
		file = file->next;
	}
	files_list_del(&options.files);
	return 0;
}
