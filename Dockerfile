FROM ubuntu:18.04

RUN   apt update && apt upgrade -y
RUN   apt install -y git gcc make
RUN   apt install --assume-yes libxext-dev libbsd-dev
RUN   cd home && git clone https://github.com/ssupremus/wolf3d.git
RUN   cp home/wolf3d/minilibx/libmlx.a home/wolf3d/minilibx/libmlx_Linux.a /usr/local/lib
RUN   cp home/wolf3d/minilibx/mlx.h /usr/local/include
RUN   cd home/wolf3d && make -C libft && sh compile-linux.sh
CMD   cd home/wolf3d && ./wolf3d maps/03
