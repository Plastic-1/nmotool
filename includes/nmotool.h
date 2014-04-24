/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmotool.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 18:11:04 by aeddi             #+#    #+#             */
/*   Updated: 2014/04/23 18:16:03 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NMOTOOL_H
# define NMOTOOL_H

# include <mach-o/loader.h>

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef struct s_bin t_bin;

t_bin
{
	struct mach_header_64	*header;
	uint64_t				size_text;
	uint32_t				off_text;
	t_bin					*next;
}

void			print_ptr_to_hex(size_t ptr, t_bool prefix, t_bool full);
void			print_byte_to_hex(unsigned char byte);

#endif
