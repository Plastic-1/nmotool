# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/14 16:00:35 by aeddi             #+#    #+#              #
#    Updated: 2016/05/05 15:51:41 by aeddi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	ft_otool
NAME2			=	ft_nm

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -pedantic -g3 -I $(LIBFT_DIR)/includes -I $(INCS_DIR)
LFLAGS			=	-L $(LIBFT_DIR) -lft

LIBFT_DIR		=	./libft
INCS_DIR		=	./includes

SRCS_DIR		=	./sources
SRCS			=	get_headers.c		\
					print_hex.c			\
					files_list.c		\
					open_close_binary.c

OBJS_DIR		=	./objects
OBJS			=	$(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))

SRCS_OT_DIR		=	$(SRCS_DIR)/ft_otool
SRCS_OT			=	main.c				\
					get_args.c			\
					parse_flags.c		\
					print_section.c		\
					find_section_32.c	\
					find_section_64.c

OBJS_OT_DIR		=	$(OBJS_DIR)/ft_otool
OBJS_OT			=	$(patsubst %.c, $(OBJS_OT_DIR)/%.o, $(SRCS_OT))

SRCS_NM_DIR		=	$(SRCS_DIR)/ft_nm
SRCS_NM			=	main.c					\
					find_symbols_32.c		\
					find_symbols_64.c		\
					get_args.c				\
					get_symbols_letters.c	\
					parse_flags.c			\
					print_symbols.c			\
					symlist.c

OBJS_NM_DIR		=	$(OBJS_DIR)/ft_nm
OBJS_NM			=	$(patsubst %.c, $(OBJS_NM_DIR)/%.o, $(SRCS_NM))

all				:	$(NAME) $(NAME2)

test			:	$(NAME) $(NAME2)
	@bash tests/tests.sh

$(NAME)			:	$(OBJS_DIR) $(OBJS) $(OBJS_OT)
	$(CC) -o $(NAME) $(OBJS) $(OBJS_OT) $(LFLAGS)

$(NAME2)		:	$(OBJS_DIR) $(OBJS) $(OBJS_NM)
	$(CC) -o $(NAME2) $(OBJS) $(OBJS_NM) $(LFLAGS)

$(OBJS_DIR)/%.o	:	$(addprefix $(SRCS_DIR)/, %.c)
	$(CC) $(CFLAGS) -o $@ -c $^

$(OBJS_OT_DIR)/%.o	:	$(addprefix $(SRCS_OT_DIR)/, %.c)
	$(CC) $(CFLAGS) -o $@ -c $^

$(OBJS_NM_DIR)/%.o	:	$(addprefix $(SRCS_NM_DIR)/, %.c)
	$(CC) $(CFLAGS) -o $@ -c $^

$(OBJS_DIR)		:	make_libft
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_OT_DIR)
	@mkdir -p $(OBJS_NM_DIR)

make_libft		:
	@$(MAKE) -C $(LIBFT_DIR)

fclean			:	clean
	rm -f $(NAME) $(NAME2)

clean			:
	rm -rf $(OBJS_DIR)

re				:	fclean all

.PHONY: clean all re fclean
