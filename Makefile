# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 19:27:57 by imedgar           #+#    #+#              #
#    Updated: 2020/11/07 10:26:49 by imedgar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D

SRC				=	main.c						\
					ft_parsing_map.c			\
					get_next_line.c				\
					get_next_line_utils.c		\
					ft_utils.c					\
					ft_end_game.c				\
					ft_check_map_utils.c		\
					ft_check_map_utils_sup.c	\
					ft_pars_n_check_map.c		\
					ft_keys.c 					\
					ft_movements.c 				\
					ft_draw.c					\
					ft_calc_tex.c				\
					ft_sprites.c				\
					ft_screenshot.c				\
					ft_draw_minimap.c  			\
					ft_utils_sup.c

INCLUDES		=	cub3d.h						\
					get_next_line.h				\
					libft.h

OBJ				=	$(addprefix $(DIR_SRC), $(SRC:.c=.o))
DEP				=	$(addprefix $(DIR_SRC), $(SRC:.c=.d))
LIBFT			=	$(DIR_LIBFT)libft.a
LIBMLX			=	$(DIR_MLX)libmlx.a

DIR_SRC			=	./srcs/
DIR_INC			=	./includes/
DIR_MLX			=	./minilibx/
DIR_LIBFT		=	./libft/
DIR_LIB_PATH	=	./lib/
BLACK_HOLE		=	/dev/null 2>&1

NORMINETTE		=	norminette
MAKE			=	make --no-print-directory -C

MLX_FLAGS		=	-lmlx -lXext -lX11 -lm
CC				=	gcc
CFLAGS			=	-g -I $(DIR_INC) -I $(DIR_MLX) -Wall -Wextra -Werror -MMD #-fsanitize=address 
RM				=	rm -rf
AR				=	ar rcs

all: $(NAME)

-include $(DEP)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
	$(CC) $(CFLAGS) -L$(DIR_LIB_PATH) $(OBJ) $(MLX_FLAGS) -lft -o $(NAME)

$(LIBFT): make_libft
	ln -f $(LIBFT) $(DIR_LIB_PATH)libft.a

make_libft:
	mkdir -p $(DIR_LIB_PATH)
	echo "Create or update $(LIBFT)!"
	$(MAKE) $(DIR_LIBFT)

$(LIBMLX): make_libmlx
	ln -f $(LIBMLX) $(DIR_LIB_PATH)libmlx.a
	echo "Oof, they stopted!\n"

make_libmlx:
	echo "\nCreate or update $(LIBMLX)!"
	echo "Screams from $(DIR_MLX:/=)!"
	chmod +x $(DIR_MLX)configure
	$(MAKE) $(DIR_MLX)

clean:
	echo "Delete all object and dependents files of $(NAME)!"
	$(RM) $(OBJ) $(DEP)

fclean: clean fclean_lib clean_minilibx
	echo "Delete $(NAME)!"
	$(RM) $(NAME) $(DIR_LIB_PATH) *.bmp valgrind-out.txt

re: fclean all

clean_minilibx:
	echo "Delete all object and dependents files of $(DIR_MLX:/=)!"
	$(MAKE) $(DIR_MLX) clean

fclean_lib:
	echo "Delete all object and dependents files of $(DIR_LIBFT:/=)!"
	$(MAKE) $(DIR_LIBFT) fclean

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt  ./cub3D maps/default.cub

norm:
	$(NORMINETTE) $(DIR_LIBFT)*.[ch]
	$(NORMINETTE) $(addprefix $(DIR_SRC), $(SRC)) $(addprefix $(DIR_INC), $(INCLUDES))

.PHONY: all re clean fclean fclean_lib clean_minilibx norm
.SILENT: $(LIBFT) make_libft $(LIBMLX) make_libmlx clean fclean clean_minilibx fclean_lib
