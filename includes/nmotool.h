/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmotool.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 18:11:04 by aeddi             #+#    #+#             */
/*   Updated: 2014/04/27 16:13:24 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NMOTOOL_H
# define NMOTOOL_H

# include <mach/boolean.h>
# include <struct.h>
# define X64T (cpu_type_t)0x1000007
# define X64ST (cpu_subtype_t)0x80000003
# define X86T (cpu_type_t)0x0000007
# define X86ST (cpu_subtype_t)0x00000003

/*
** Aux otool functions
*/
void			display_text_sec32(t_text *text, char *file);
void			find_text_sec32(t_text *text, struct mach_header *mach);
void			display_text_sec64(t_text *text, char *file);
void			find_text_sec64(t_text *text, struct mach_header_64 *mach);

/*
** Print functions
*/
int				error_printer(char *str, int fd);
void			print_ptr_to_hex(size_t ptr, boolean_t prefix, boolean_t len64);
void			print_byte_to_hex(unsigned char byte);

/*
** Aux otool functions
*/
void			find_print_symbol32(t_text *text);
void			find_print_symbol64(t_text *text);
char			set_right_sym(uint8_t n_type, uint16_t n_sect);

/*
** Symlist functions
*/
t_symlist		*add_sym(char *name, struct nlist *nl32, struct nlist_64 *nl64);
t_symlist		*sort_list32(t_symlist *root);
t_symlist		*sort_list64(t_symlist *root);
void			print_list(t_symlist *root);
void			free_symlist(t_symlist *root);

#endif
