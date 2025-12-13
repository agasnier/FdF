NAME = fdf

CC = cc
CFLAGS = -Werror -Wall -Wextra

MLX_PATH = ressources/minilibx-linux
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)/$(MLX_NAME)

LIBS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

SRCS =	fdf.c \
		ft_control.c \
		ft_draw.c \
		ft_heat_map.c \
		ft_helper.c \
		ft_initialization.c \
		ft_projection.c \
		ft_put_line_helper.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c 
	
OBJS = $(SRCS:.c=.o)

HEADER =	fdf.h \
			get_next_line/get_next_line.h

SRCS_BONUS = 

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

HEADER_BONUS =	bonus/fdf_bonus.h

all: $(MLX) $(NAME)

$(MLX):
	make -C $(MLX_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

bonus: $(MLX) $(NAME)

$(BONUS_NAME): $(OBJS) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_BONUS) $(LIBS) -o $(BONUS_NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)
	make clean -C $(MLX_PATH)

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus

