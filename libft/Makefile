# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 12:06:57 by aeddi             #+#    #+#              #
#    Updated: 2014/01/24 21:04:43 by aeddi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
LIBFLAGS		=	rc
RM				=	rm -f
SRCS			=	ft_memset.c			\
					ft_bzero.c			\
					ft_memcpy.c			\
					ft_memccpy.c		\
					ft_memmove.c		\
					ft_memchr.c			\
					ft_memcmp.c			\
					ft_strlen.c			\
					ft_strdup.c			\
					ft_strcpy.c			\
					ft_strncpy.c		\
					ft_strcat.c			\
					ft_strncat.c		\
					ft_strlcat.c		\
					ft_strchr.c			\
					ft_strrchr.c		\
					ft_strstr.c			\
					ft_strnstr.c		\
					ft_strcmp.c			\
					ft_strncmp.c		\
					ft_atoi.c			\
					ft_isalpha.c		\
					ft_isdigit.c		\
					ft_isalnum.c		\
					ft_isascii.c		\
					ft_isprint.c		\
					ft_toupper.c		\
					ft_tolower.c		\
					ft_memalloc.c		\
					ft_memdel.c			\
					ft_strnew.c			\
					ft_strdel.c			\
					ft_strclr.c			\
					ft_striter.c		\
					ft_striteri.c		\
					ft_strmap.c			\
					ft_strmapi.c		\
					ft_strequ.c			\
					ft_strnequ.c		\
					ft_strsub.c			\
					ft_strjoin.c		\
					ft_strtrim.c		\
					ft_strsplit.c		\
					ft_itoa.c			\
					ft_putchar.c		\
					ft_putstr.c			\
					ft_putendl.c		\
					ft_putnbr.c			\
					ft_putchar_fd.c		\
					ft_putstr_fd.c		\
					ft_putendl_fd.c		\
					ft_putnbr_fd.c		\
					ft_lstnew.c			\
					ft_lstdelone.c		\
					ft_lstdel.c			\
					ft_lstadd.c			\
					ft_lstiter.c		\
					ft_lstmap.c			\
					ft_rotx.c			\
					ft_revstr.c			\
					get_next_line.c		\
					get_next_line_mfd.c	\
					ft_abs.c			\
					ft_tabdel.c			\
					ft_tablen.c			\
					dlst_new.c			\
					dlst_add_head.c		\
					dlst_add_tail.c		\
					dlst_del.c			\
					ft_strreplace.c		\
					ft_strcount.c		\
					ft_strjoin_tw.c		\
					ft_skip_space.c


OBJS			=	$(SRCS:.c=.o)

all				:	$(NAME)

$(NAME)			:	$(OBJS)
	$(AR) $(LIBFLAGS) $(NAME) $(OBJS)

%.o				:	%.c
	$(CC) $(CFLAGS) -c $<

fclean			:	clean
	$(RM) $(NAME)

clean			:
	$(RM) $(OBJS)

re				:	fclean all

.PHONY: clean all re fclean
