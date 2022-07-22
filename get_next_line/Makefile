SRCS	= get_next_line.c get_next_line_utils.c

OBJS	= ${SRCS:.c=.o}

NAME	= gnl.a

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
