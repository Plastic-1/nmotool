/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 16:31:52 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/11 11:51:55 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <nmotool.h>

int		error_printer(char *str, int fd)
{
	ft_putendl(str);
	if (fd && close(fd) == -1)
		ft_putendl("error: file closing impossible");
	return (1);
}

void	print_byte_to_hex(unsigned char byte)
{
	char	str[2];
	short	count;
	short	char_hex;

	count = -1;
	while (++count != 2)
	{
		char_hex = byte % 16;
		byte /= 16;
		if (char_hex < 10)
			str[count] = char_hex + '0';
		else
			str[count] = (char_hex % 10) + 'a';
	}
	ft_putchar_fd(str[1], 1);
	ft_putchar_fd(str[0], 1);
}

void	print_ptr_to_hex(size_t ptr, boolean_t prefix, boolean_t len64)
{
	char	str[16];
	short	count;
	short	char_hex;

	count = -1;
	while (++count != 16)
	{
		char_hex = ptr % 16;
		ptr /= 16;
		if (char_hex < 10)
			str[count] = char_hex + '0';
		else
			str[count] = (char_hex % 10) + 'a';
	}
	count--;
	if (!len64)
		count -= 8;
	if (prefix)
		ft_putstr_fd("0x", 1);
	while (count >= 0)
	{
		ft_putchar_fd(str[count], 1);
		count--;
	}
}
