/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 09:04:14 by aeddi             #+#    #+#             */
/*   Updated: 2013/11/27 15:31:55 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	neg;
	int	i;

	res = 0;
	neg = 0;
	i = 0;
	while (*str == ' ' || *str == '\t' || *str == '\f' || *str == '\v'
			|| *str == '\n' || *str == '\r')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg++;
		i++;
		str++;
	}
	while (*str >= '0' && *str <= '9' && i <= 1)
	{
		res *= 10;
		res += *str++ - '0';
	}
	if (neg)
		res *= -1;
	return (res);
}
