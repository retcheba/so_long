SRCS	= main.c mapping.c so_long_utils.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJS	= $(SRCS:.c=.o)
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
NAME	= so_long
RM		= rm -f
MLX		= mlx_linux/libmlx.a

all:		$(NAME)

%.o: 		%.c
			$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(MLX):	
			make -C mlx_linux/

$(NAME): 	$(OBJS) $(MLX)
			$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
			$(RM) $(OBJS)
			make clean -C mlx_linux/

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
