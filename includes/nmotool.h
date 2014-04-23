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

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

void			print_ptr_to_hex(size_t ptr, t_bool prefix, t_bool full);
void			print_byte_to_hex(unsigned char byte);

#endif
