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
		ft_helper.c \
		ft_initialization.c \
		ft_projection.c \
		ft_put_line_helper.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

SRCS_BONUS =	ft_control_bonus.c \
				ft_heat_map_bonus.c 

HEADER =	fdf.h \
			get_next_line/get_next_line.h \
			fdf_bonus.h \
			struct.h

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS:.c=_bonus.o) $(SRCS_BONUS:.c=_bonus.o)

all: $(MLX) $(NAME)

$(MLX):
	@echo "Compilation MLX..."
	@make -C $(MLX_PATH) > /dev/null 2>&1
	@echo "Compilation MLX OK."

$(NAME): .manda $(OBJS) 
	@echo "Compilation FDF..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "Compilation FDF OK."

.manda:
	@if [ -f .bonus ]; then \
		echo "Switch to manda..."; \
		$(MAKE) fclean > /dev/null 2>&1; \
	fi
	@touch .manda

bonus: .bonus $(MLX) $(OBJS_BONUS)
	@echo "Compilation FDF BONUS..."
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBS) -o $(NAME)
	@echo "Compilation FDF BONUS OK."

.bonus: 
	@if [ -f .manda ]; then \
		echo "Switch to bonus..."; \
		$(MAKE) fclean > /dev/null 2>&1; \
	fi
	@touch .bonus

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	
%_bonus.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -D BONUS -c $< -o $@

clean:
	@rm -rf $(OBJS) $(OBJS_BONUS)
	@if [ ! -f .bonus ] && [ ! -f .manda ]; then \
		make clean -C $(MLX_PATH)  > /dev/null 2>&1; \
	fi
	@rm -f .bonus .manda

fclean: clean
	@rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re bonus

