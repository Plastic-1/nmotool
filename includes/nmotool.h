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
	void					*start;
	void					*end;
	struct mach_header_64	*mach64;
	uint64_t				diff64;
	struct mach_header		*mach32;
	uint32_t				diff32;
}				t_text;

/*
** Print functions
*/
int				error_printer(char *str, int fd);
void			print_ptr_to_hex(size_t ptr, boolean_t prefix, boolean_t len64);
void			print_byte_to_hex(unsigned char byte);

/*
** Aux otool functions
*/
void			display_text_sec32(t_text *text, char *file);
void			find_text_sec32(t_text *text, struct mach_header *mach);
void			display_text_sec64(t_text *text, char *file);
void			find_text_sec64(t_text *text, struct mach_header_64 *mach);
#endif
