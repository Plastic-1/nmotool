/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 15:37:42 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/13 06:04:09 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <sys/stat.h>
# include <mach/boolean.h>
# include <mach-o/loader.h>

typedef enum				e_arch
{
	A_DEF,
	A_ALL,
	A_X64,
	A_X32
}							t_arch;

typedef	struct				s_filelst
{
	char					*name;
	struct s_filelst		*next;
}							t_filelst;

typedef struct				s_arg_ot
{
	t_filelst				*files;
	boolean_t				p_text;
	boolean_t				p_data;
	boolean_t				p_cust;
	char					*seg_n;
	char					*sect_n;
	t_arch					arch;
}							t_arg_ot;

typedef struct				s_arg_nm
{
	t_filelst				*files;
	boolean_t				p_rev;
	boolean_t				p_short;
	boolean_t				p_unsort;
	boolean_t				o_undef;
	boolean_t				n_undef;
	boolean_t				o_ext;
	t_arch					arch;
}							t_arg_nm;

typedef struct				s_head
{
	struct mach_header		*mach32;
	struct mach_header_64	*mach64;
}							t_head;

typedef struct				s_symlist
{
	char					*name;
	char					letter;
	uint8_t					n_type;
	uint8_t					n_sect;
	uint64_t				n_value;
	struct s_symlist		*next;
	struct s_symlist		*prev;
}							t_symlist;

typedef struct				s_bin
{
	int						fd;
	struct stat				st;
	void					*data;
}							t_bin;

typedef struct				s_sect
{
	char					*start;
	char					*end;
	uint64_t				offset;
	boolean_t				len64;
}							t_sect;

#endif
