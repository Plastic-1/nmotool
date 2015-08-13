/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 16:31:52 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/13 00:04:00 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <nmotool.h>

void	print_byte_to_hex(char byte)
{
	char			str[2];
	short			count;
	short			char_hex;
	unsigned char	cast;

	cast = (unsigned char)byte;
	count = -1;
	while (++count != 2)
	{
		char_hex = cast % 16;
		cast /= 16;
		if (char_hex < 10)
			str[count] = char_hex + '0';
		else
			str[count] = (char_hex % 10) + 'a';
	}
	ft_putchar(str[1]);
	ft_putchar(str[0]);
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
		ft_putstr("0x");
	while (count >= 0)
		ft_putchar(str[count--]);
}
