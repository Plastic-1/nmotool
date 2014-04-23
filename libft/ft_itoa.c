/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 19:29:18 by aeddi             #+#    #+#             */
/*   Updated: 2013/12/18 12:34:59 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*filer(char *result, int n, unsigned int n_bis, int neg)
{
	int		res;
	int		index;

	index = 0;
	if (neg)
	{
		result[index] = '-';
		index++;
	}
	while (n_bis > 0)
	{
		res = n / n_bis;
		result[index] = res + '0';
		n %= n_bis;
		n_bis /= 10;
		index++;
	}
	result[index] = '\0';
	return (result);
}

char		*ft_itoa(int n)
{
	char			*result;
	int				neg;
	int				count;
	unsigned int	buf;
	unsigned int	n_bis;

	count = 0;
	neg = 0;
	if (n < 0)
	{
		neg++;
		n *= -1;
	}
	n_bis = 1;
	buf = n;
	while (buf / 10 > 0)
	{
		count++;
		n_bis *= 10;
		buf /= 10;
	}
	result = ft_strnew(neg + count);
	return (filer(result, n, n_bis, neg));
}
