SRCS	= ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_putnbr_pos.c ft_puthexa.c ft_putptr.c ft_puthexa_maj.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

RM		= rm -f

$(NAME):	${OBJS} 
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean
