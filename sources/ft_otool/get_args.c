/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/mail/plastic>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 17:14:39 by plastic           #+#    #+#             */
/*   Updated: 2015/08/13 01:50:18 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <struct.h>
#include <nmotool.h>

static int	parse_args(int ac, char **av, t_arg_ot *options)
{
	size_t	count;

	count = 1;
	while (count < (size_t)ac)
	{
		if (av[count][0] == '-')
		{
			if (parse_flags_ot(ac, av, options, &count))
				return 1;
		}
		else
			files_list_add(&options->files, av[count]);
		count++;
	}
	return 0;
}

void		print_parse_error(char *filename, char *message)
{
	ft_putstr_fd("Parse error: ", 2);
	ft_putendl_fd(message, 2);
	ft_putstr_fd("Usage: ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(" [ -td [ -s segname sectname ]] ", 2);
	ft_putendl_fd("[ -arch arch_flag ] [ file ... ]\n", 2);
	ft_putendl_fd("You must specify at least one section to print:", 2);
	ft_putendl_fd("\t-t\tPrint (__TEXT,__text) section", 2);
	ft_putendl_fd("\t-d\tPrint (__DATA,__data) section", 2);
	ft_putendl_fd("\t-s segname sectname\tPrint custom section\n", 2);
	ft_putendl_fd("You can specify one or more arch_flag for fat binaries:", 2);
	ft_putendl_fd("\t-arch i386\tDisplay i386 arch section", 2);
	ft_putendl_fd("\t-arch x86_64\tDisplay x86_64 arch section", 2);
}

int			get_args_ot(int ac, char **av, t_arg_ot *options)
{
	options->files = NULL;
	options->p_text = FALSE;
	options->p_data = FALSE;
	options->p_cust = FALSE;
	options->seg_n = NULL;
	options->sect_n = NULL;
	options->arch = A_DEF;
	if (parse_args(ac, av, options))
		return 1;
	if (!options->p_text && !options->p_data && !options->p_cust)
	{
		print_parse_error(av[0], "You must set at least one section flag");
		return 1;
	}
	else if (files_list_count(options->files) == 0)
	{
		print_parse_error(av[0], "You must specify at least one file");
		return 1;
	}
	return 0;
}
