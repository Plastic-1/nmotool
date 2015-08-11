/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 09:04:14 by aeddi             #+#    #+#             */
/*   Updated: 2014/05/19 19:32:08 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_atoi(const char *str)
{
	int	res;
	int	neg;
	int	sig;

	res = 0;
	neg = 0;
	sig = 0;
	while (ft_isspace(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg++;
		sig++;
		str++;
	}
	while (*str >= '0' && *str <= '9' && sig <= 1)
	{
		res *= 10;
		res += *str++ - '0';
	}
	res *= (neg) ? -1 : 1;
	return (res);
}
