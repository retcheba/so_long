SRCS	= main.c
OBJS	= $(SRCS:.c=.o)
CC		= gcc
FLAGS 	= -Wall -Wextra
NAME	= so_long
RM		= rm -f
MLX		= mlx_linux/libmlx_Linux.a

all:		$(NAME)

%.o: 		%.c
			$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(MLX):	
			make -C mlx_linux

$(NAME): 	$(OBJS) $(MLX)
			$(CC) $(FLAGS) $(OBJS) $(MLX) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


clean:
			$(RM) $(OBJS)
			make clean -C mlx_linux

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
