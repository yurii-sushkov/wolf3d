make -C libft
clang *.c -o wolf3d -L./libft -L./minilibx -lft -lm -lmlx -lXext -lX11 -lbsd -g3
