all:
	clear && cc -Werror -Wextra -Wall *.c get_next_line/*.c ressources/minilibx-linux/libmlx.a -L -lmlx -lXext -lX11
