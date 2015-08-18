/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 14:43:16 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/18 18:03:59 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach/boolean.h>
#include <libft.h>
#include <struct.h>
#include <nmotool.h>

static void	print_filename_arch(char *filename, char *arch)
{
	ft_putstr(filename);
	if (arch)
		ft_putstr(arch);
	ft_putendl(":");
}

static void	print_sections(t_arg_ot *options, t_head *headers, char *filename)
{
	if (headers->mach64 && (options->arch == A_ALL
		|| options->arch == A_DEF || options->arch == A_X64))
	{
		if (options->arch == A_ALL && headers->mach32)
			print_filename_arch(filename, " (architecture x86_64)");
		if (options->p_text)
			find_section_64(headers, SEG_TEXT, SECT_TEXT);
		if (options->p_data)
			find_section_64(headers, SEG_DATA, SECT_DATA);
		if (options->p_cust)
			find_section_64(headers, options->seg_n, options->sect_n);
	}
	if (headers->mach32 && (options->arch == A_ALL || options->arch == A_X32))
	{
		if (options->arch == A_ALL && headers->mach64)
			print_filename_arch(filename, " (architecture i386)");
		if (options->p_text)
			find_section_32(headers, SEG_TEXT, SECT_TEXT);
		if (options->p_data)
			find_section_32(headers, SEG_DATA, SECT_DATA);
		if (options->p_cust)
			find_section_32(headers, options->seg_n, options->sect_n);
	}
}

static int	otool(char *filename, t_arg_ot *options, t_bin *binary)
{
	t_head	headers;

	get_binary_headers(binary->data, &headers);
	if (!headers.mach32 && !headers.mach64)
	{
		ft_putstr(filename);
		ft_putstr(": ");
		ft_putendl("is not an object file");
		return (1);
	}
	if (options->arch == A_ALL && (!headers.mach32 || !headers.mach64))
		print_filename_arch(filename, NULL);
	print_sections(options, &headers, filename);
	return (0);
}

int			main(int ac, char **av)
{
	t_bin			binary;
	t_arg_ot		options;
	t_filelst		*file;

	if (get_args_ot(ac, av, &options))
		return (1);
	file = options.files;
	while (file)
	{
		if (open_binary(file->name, &binary))
			return (2);
		if (otool(file->name, &options, &binary))
			return (3);
		if (close_binary(file->name, &binary))
			return (4);
		file = file->next;
	}
	files_list_del(&options.files);
	return (0);
}
