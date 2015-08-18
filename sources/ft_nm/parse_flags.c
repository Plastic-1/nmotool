/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 17:58:00 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/18 17:58:02 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <struct.h>
#include <nmotool.h>

static int	parse_arch(int ac, char **av, t_arg_nm *options, size_t *count)
{
	if (*count < (size_t)ac)
	{
		if (ft_strcmp(av[*count], "i386") == 0)
		{
			if (options->arch == A_ALL || options->arch == A_X64)
				options->arch = A_ALL;
			else
				options->arch = A_X32;
			return (0);
		}
		else if (ft_strcmp(av[*count], "x86_64") == 0)
		{
			if (options->arch == A_ALL || options->arch == A_X32)
				options->arch = A_ALL;
			else
				options->arch = A_X64;
			return (0);
		}
	}
	print_parse_error(av[0], "You must specify a valid arch_flag");
	return (1);
}

static int	flags_filter(char flag, t_arg_nm *options)
{
	if (flag == 'r')
		options->p_rev = TRUE;
	else if (flag == 'j')
		options->p_short = TRUE;
	else if (flag == 'p')
		options->p_unsort = TRUE;
	else if (flag == 'u')
		options->o_undef = TRUE;
	else if (flag == 'U')
		options->n_undef = TRUE;
	else if (flag == 'g')
		options->o_ext = TRUE;
	else
		return (1);
	return (0);
}

static int	parse_other_flags(char *flag, t_arg_nm *options)
{
	unsigned int	count;

	count = 1;
	while (flag[count])
	{
		if (flags_filter(flag[count], options))
		{
			print_parse_error(flag, "Invalid parameter");
			return (1);
		}
		count++;
	}
	if (count == 1)
	{
		print_parse_error(flag, "Invalid parameter");
		return (1);
	}
	return (0);
}

int			parse_flags_nm(int ac, char **av, t_arg_nm *options, size_t *count)
{
	if (ft_strcmp(av[*count], "-arch") == 0)
	{
		*count += 1;
		return (parse_arch(ac, av, options, count));
	}
	else
		return (parse_other_flags(av[*count], options));
}
