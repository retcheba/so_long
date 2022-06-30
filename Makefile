SRCS	= main.c
OBJS	= $(SRCS:.c=.o)
CC		= gcc
FLAGS 	= -Wall -Wextra -Werror
NAME	= so_long
RM		= rm -f
MLX		= mlx/libmlx.a

all:		$(NAME)

%.o: 		%.c
			$(CC) $(FLAGS) -Imlx -c $< -o $@

$(MLX):	
			make -C mlx

$(NAME): 	$(OBJS) $(MLX)
			$(CC) $(FLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)


clean:
			$(RM) $(OBJS)
			make clean -C mlx

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
