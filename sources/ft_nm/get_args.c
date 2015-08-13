/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/mail/plastic>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 17:14:39 by plastic           #+#    #+#             */
/*   Updated: 2015/08/13 06:13:01 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <struct.h>
#include <nmotool.h>

static int	parse_args(int ac, char **av, t_arg_nm *options)
{
	size_t	count;

	count = 1;
	while (count < (size_t)ac)
	{
		if (av[count][0] == '-')
		{
			if (parse_flags_nm(ac, av, options, &count))
				return 1;
		}
		else
			files_list_add(&options->files, av[count]);
		count++;
	}
	if (options->o_undef && options->n_undef)
	{
		print_parse_error(av[0], "can't specifiy both -U and -u");
		return 1;
	}
	return 0;
}

void		print_parse_error(char *filename, char *message)
{
	ft_putstr_fd("Parse error: ", 2);
	ft_putendl_fd(message, 2);
	ft_putstr_fd("Usage: ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(" [ -rjpuUg [ -arch arch_flag ] [ file ... ]\n", 2);
	ft_putendl_fd("You can use print flags:", 2);
	ft_putendl_fd("\t-r\tPrint in reverse order", 2);
	ft_putendl_fd("\t-p\tPrint unsorted (symbols table order)", 2);
	ft_putendl_fd("\t-j\tPrint only name (no value or type)\n", 2);
	ft_putendl_fd("You can use filter flags:", 2);
	ft_putendl_fd("\t-u\tPrint only undefined symbols", 2);
	ft_putendl_fd("\t-U\tDon't print undefined symbols", 2);
	ft_putendl_fd("\t-g\tPrint only external symbols\n", 2);
	ft_putendl_fd("You can specify one or more arch_flag for fat binaries:", 2);
	ft_putendl_fd("\t-arch i386\tDisplay i386 arch section", 2);
	ft_putendl_fd("\t-arch x86_64\tDisplay x86_64 arch section", 2);
}

int			get_args_nm(int ac, char **av, t_arg_nm *options)
{
	options->files = NULL;
	options->p_rev = FALSE;
	options->p_short = FALSE;
	options->p_unsort = FALSE;
	options->o_undef = FALSE;
	options->n_undef = FALSE;
	options->o_ext = FALSE;
	options->arch = A_DEF;
	if (parse_args(ac, av, options))
		return 1;
	else if (files_list_count(options->files) == 0)
	{
		print_parse_error(av[0], "You must specify at least one file");
		return 1;
	}
	return 0;
}
