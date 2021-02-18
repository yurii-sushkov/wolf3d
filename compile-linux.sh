sudo apt install -y git gcc make
sudo apt install --assume-yes libxext-dev libbsd-dev
sudo cp minilibx/libmlx.a /usr/local/lib
sudo cp minilibx/libmlx_Linux.a /usr/local/lib
sudo cp minilibx/mlx.h /usr/local/include
make -C libft
gcc *.c -o wolf3d -L./libft -L./minilibx -lft -lm -lmlx -lXext -lX11 -lbsd
./wolf3d maps/03
