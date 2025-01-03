CC =  cc
CFLAGS = -Wall -Wextra -Werror
OBJS  = $(SRCS:.c=.o)

SRCS = srcs/bonus.c srcs/key_action.c srcs/main.c srcs/map_init.c srcs/plot_line.c srcs/utils.c \
	   srcs/get_next_line/get_next_line.c srcs/get_next_line/get_next_line_utils.c

LIBFT = libft.a

LIBFTDIR = ./srcs/libft

NAME = fdf

all : ${NAME}


${NAME} : ${OBJS}
	make -C ${LIBFTDIR}
	cc ${CFLAGS}  -lmlx -framework OpenGL -framework Appkit -lz -o $@ $^ ${LIBFTDIR}/${LIBFT}

.c.o :
	${CC} ${CFLAGS} -c $< -o $@

clean :
	rm -f ${OBJS}
	rm -f ${LIBFTDIR}/*.o

fclean : clean 
	rm -f ${NAME}
	rm -f ${LIBFTDIR}/${LIBFT}

re : fclean all

.PHONY : all bonus clean fclean re
