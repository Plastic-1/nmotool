/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmotool.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 18:11:04 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/13 05:50:48 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NMOTOOL_H
# define NMOTOOL_H

# include <struct.h>

/*
** Parse binary functions
*/
void			get_binary_headers(void *ptr, t_head *headers);

void			find_section_32(t_head *headers, char *segname, char *sectname);
void			find_section_64(t_head *headers, char *segname, char *sectname);

void			find_symbols_32(t_head *headers, t_arg_nm *options);
void			find_symbols_64(t_head *headers, t_arg_nm *options);

/*
** File functions
*/
int				open_binary(char *filename, t_bin *binary);
int				close_binary(char *filename, t_bin *binary);

/*
** Parameters functions
*/
int				parse_flags_ot(int ac, char **av, t_arg_ot *options, size_t *cnt);
int				get_args_ot(int ac, char **av, t_arg_ot *options);

int				parse_flags_nm(int ac, char **av, t_arg_nm *options, size_t *cnt);
int				get_args_nm(int ac, char **av, t_arg_nm *options);

/*
** Print functions
*/
void			print_byte_to_hex(char byte);
void			print_ptr_to_hex(size_t ptr, boolean_t prefix, boolean_t len64);
void			print_parse_error(char *filename, char *message);

void			print_section(t_sect *section, char *segname, char *sectname);

void			print_list(t_symlist *root, t_arg_nm *options, boolean_t len64);
void			get_symbols_letters(t_symlist *root, char *sect_names[]);

/*
** Files list functions
*/
void			files_list_add(t_filelst **lst, char *filename);
void			files_list_del(t_filelst **lst);
unsigned int	files_list_count(t_filelst *lst);

/*
** Symbols list functions
*/
t_symlist		*add_sym(char *name, void *nl, t_symlist *prv, boolean_t len64);
t_symlist		*get_tail(t_symlist *iter);
void			swap_symbols(t_symlist *sym_a, t_symlist *sym_b);
void			free_symlist(t_symlist *root);

#endif
