# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/11 13:23:23 by ysushkov          #+#    #+#              #
#    Updated: 2018/08/06 12:09:06 by ysushkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=		wolf3d

FLAGS	:=		-Wall -Werror -Wextra -O2

SRC		:=		main.c validation.c process.c textures.c deal_key.c mouse.c \
				calc.c draw.c

HEAD	:=		./includes/wolf3d.h

OBJ		:=		$(SRC:.c=.o)

LIB		:=		./libft/libft.a

OS		:=		$(shell uname -s)

ifeq ($(OS), Darwin)
	MLX		:=		-L minilibx_macos -lmlx -framework OpenGL -framework AppKit
else
	MLX		:=		-L./libft -L./minilibx -lft -lm -lmlx -lXext -lX11 -lbsd -g3
endif

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C libft
			@clang $(FLAGS) -I $(HEAD) -c $(SRC)
			@clang $(FLAGS) $(LIB) $(MLX) -o $(NAME) $(OBJ)
			@echo "\033[92mDONE\033[0m"

$(OBJ):		%.o: %.c
			clang $(FLAGS) -I $(HEAD) -c $< -o $@

clean:
			@make -C libft clean
			@/bin/rm -f $(OBJ)
			@echo "\033[92mObject files have been deleted\033[0m"

fclean:		clean
			@make -C libft fclean
			@/bin/rm -f $(NAME)
			@echo "\033[92mExecutables have been deleted\033[0m"

re:			fclean all

.PHONY:all clean fclean re
