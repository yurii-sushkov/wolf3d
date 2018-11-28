make -C libft
gcc *.c -o wolf3d -L./libft -L./minilibx -lft -lm -lmlx -lXext -lX11 -lbsd
