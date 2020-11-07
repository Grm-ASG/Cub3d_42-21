# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/03 23:24:43 by imedgar           #+#    #+#              #
#    Updated: 2020/11/04 19:04:22 by imedgar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRC		=	ft_atoi.c			\
			ft_bzero.c			\
			ft_calloc.c			\
			ft_isalnum.c		\
			ft_isalpha.c		\
			ft_isascii.c		\
			ft_isdigit.c		\
			ft_isprint.c		\
			ft_itoa.c			\
			ft_memccpy.c		\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_memcpy.c			\
			ft_memmove.c		\
			ft_memset.c			\
			ft_putchar_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\
			ft_putstr_fd.c		\
			ft_split.c			\
			ft_strchr.c			\
			ft_strdup.c			\
			ft_strjoin.c		\
			ft_strlcat.c		\
			ft_strlcpy.c		\
			ft_strlen.c			\
			ft_strmapi.c		\
			ft_strncmp.c		\
			ft_strnstr.c		\
			ft_strrchr.c		\
			ft_strtrim.c		\
			ft_substr.c			\
			ft_tolower.c		\
			ft_toupper.c		\
			ft_strcmp.c

HEADER	=	libft.h

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -c -MMD
RM		=	rm -f
AR		=	ar rcs
OBJ		=	$(SRC:.c=.o)
DEP     = $(SRC:.c=.d)


all: $(NAME)

-include $(DEP)

$(NAME): $(OBJ)
	$(AR) $@ $(OBJ)

clean:
	$(RM) $(OBJ) $(DEP) $(OBJBNS)

fclean: clean
	$(RM) $(NAME)

re: fclean all