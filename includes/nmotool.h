/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmotool.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 18:11:04 by aeddi             #+#    #+#             */
/*   Updated: 2014/04/25 15:04:16 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NMOTOOL_H
# define NMOTOOL_H

# include <mach/boolean.h>

typedef struct	s_text
{
	void		*start;
	void		*end;
	uint64_t	diff;
}				t_text;

void			print_ptr_to_hex(size_t ptr, boolean_t prefix, boolean_t full);
void			print_byte_to_hex(unsigned char byte);

#endif
