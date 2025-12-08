all:
	clear && cc -Werror -Wextra -Wall *.c get_next_line/*.c ressources/minilibx_macos/libmlx.a -L  -lmlx -lXext -lX11 -lm

mac:
	clear && cc -Werror -Wextra -Wall *.c get_next_line/*.c -I./ressources/minilibx_macos -L./ressources/minilibx_macos -lmlx -framework OpenGL -framework AppKit
