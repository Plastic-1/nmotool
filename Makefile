# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/14 16:00:35 by aeddi             #+#    #+#              #
#    Updated: 2015/08/11 11:49:17 by aeddi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	ft_nm
NAME2			=	ft_otool
CC				=	cc
GDB				?=	0
ifeq ($(GDB), 1)
	CFLAGS		=	-Wall -Wextra -Werror -pedantic -g3 -I $(LIBFT_DIR)/includes -I $(INCS_DIR)
else
	CFLAGS		=	-Wall -Wextra -Werror -pedantic -O3 -I $(LIBFT_DIR)/includes -I $(INCS_DIR)
endif
LFLAGS			=	-L $(LIBFT_DIR) -lft
LIBFT_DIR		=	./libft
INCS_DIR		=	./includes
OBJS_DIR		=	./objects
SRCS_DIR		=	./sources
OBJS			=	$(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))
OBJS2			=	$(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS2))
SRCS			=	ft_nm.c			\
					ft_nm_aux.c		\
					print_data.c	\
					symlist.c
SRCS2			=	ft_otool.c		\
					ft_otool_aux.c	\
					print_data.c

all				:	$(NAME) $(NAME2)

$(NAME)			:	$(OBJS_DIR) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LFLAGS)

$(NAME2)		:	$(OBJS_DIR) $(OBJS2)
	$(CC) -o $(NAME2) $(OBJS2) $(LFLAGS)

$(OBJS_DIR)/%.o	:	$(addprefix $(SRCS_DIR)/, %.c)
	$(CC) $(CFLAGS) -o $@ -c $^


$(OBJS_DIR)		:	make_libft
	@mkdir -p $(OBJS_DIR)

make_libft		:
	@$(MAKE) -C $(LIBFT_DIR)

fclean			:	clean
	rm -f $(NAME) $(NAME2)

clean			:
	rm -rf $(OBJS_DIR)

re				:	fclean all

.PHONY: clean all re fclean
