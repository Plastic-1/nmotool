/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/18 18:05:22 by aeddi             #+#    #+#             */
/*   Updated: 2016/05/07 13:17:25 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <struct.h>
#include <nmotool.h>

static int	parse_arch(int ac, char **av, t_arg_ot *options, size_t *count)
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

static int	parse_sect_name(int ac, char **av, t_arg_ot *options, size_t *count)
{
	if (*count + 1 < (size_t)ac)
	{
		options->p_cust = TRUE;
		options->seg_n = av[*count];
		*count += 1;
		options->sect_n = av[*count];
		return (0);
	}
	print_parse_error(av[0], "You must specify segment and section after -s");
	return (1);
}

static int	parse_sect_flag(char *flag, t_arg_ot *options)
{
	unsigned int	count;

	count = 1;
	while (flag[count])
	{
		if (flag[count] == 't')
			options->p_text = TRUE;
		else if (flag[count] == 'd')
			options->p_data = TRUE;
		else
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

int			parse_flags_ot(int ac, char **av, t_arg_ot *options, size_t *count)
{
	if (ft_strcmp(av[*count], "-arch") == 0)
	{
		*count += 1;
		return (parse_arch(ac, av, options, count));
	}
	else if (ft_strcmp(av[*count], "-s") == 0)
	{
		*count += 1;
		return (parse_sect_name(ac, av, options, count));
	}
	else
		return (parse_sect_flag(av[*count], options));
}
