SRCS	= srcs/main.c srcs/mapping.c srcs/put_image.c srcs/keypress.c srcs/keypress2.c srcs/so_long_utils.c
OBJS	= $(SRCS:.c=.o)
CC		= gcc
FLAGS	= -g -Wall -Wextra -Werror
NAME	= so_long
RM		= rm -f
MLX		= mlx_linux/libmlx.a
GNL		= get_next_line/gnl.a
PRINTF	= ft_printf/libftprintf.a

all:		$(NAME)

clean:
			$(RM) $(OBJS)
			make clean -C mlx_linux/
			make fclean -C get_next_line/
			make fclean -C ft_printf/

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

%.o: 		%.c
			$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(MLX):	
			make -C mlx_linux/

$(GNL):	
			make -C get_next_line/

$(PRINTF):
			make -C ft_printf/

$(NAME): 	$(OBJS) $(MLX) $(GNL) $(PRINTF)
			$(CC) $(FLAGS) $(OBJS) $(MLX) $(GNL) $(PRINTF) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

.PHONY:		all clean fclean re
