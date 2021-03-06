/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 18:03:20 by aeddi             #+#    #+#             */
/*   Updated: 2016/05/07 13:37:14 by aeddi            ###   ########.fr       */
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
	if (headers->mach32 && ((options->arch == A_ALL || options->arch == A_X32)
			|| (options->arch == A_DEF && !headers->mach64)))
	{
		if (options->arch == A_ALL && headers->mach64)
			print_filename_arch(filename, " (for architecture i386)");
		find_symbols_32(headers, options);
	}
}

static int	nm(char *filename, t_arg_nm *options, t_bin *binary, size_t count)
{
	t_head	headers;

	get_binary_headers(binary->data, &headers);
	if (!headers.mach32 && !headers.mach64)
	{
		print_file_error(filename,
				"The file was not recognized as a valid object file.");
		return (1);
	}
	if ((!headers.mach32 && options->arch == A_X32) ||
		(!headers.mach64 && options->arch == A_X64))
		print_file_error(filename, "No architecture specified.");
	else if (((options->arch == A_ALL && (!headers.mach32 || !headers.mach64))
		|| options->arch == A_DEF ||
		(options->arch == A_X32 && headers.mach32 && !headers.mach64) ||
		(options->arch == A_X64 && headers.mach64 && !headers.mach32))
		&& count > 1
		&& !(options->arch == A_DEF && headers.mach32 && headers.mach64))
		print_filename_arch(filename, NULL);
	print_symbols(filename, options, &headers);
	return (0);
}

int			main(int ac, char **av)
{
	t_bin			binary;
	t_arg_nm		options;
	t_filelst		*file;
	size_t			count;

	if (get_args_nm(ac, av, &options))
		return (1);
	file = options.files;
	count = files_list_count(options.files);
	while (file)
	{
		if (!open_binary(file->name, &binary))
		{
			nm(file->name, &options, &binary, count);
			if (close_binary(file->name, &binary))
				return (2);
		}
		file = file->next;
	}
	files_list_del(&options.files);
	return (0);
}
