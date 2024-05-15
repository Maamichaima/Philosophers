SRC = main.c inisialiser.c routine.c monitor.c check_bonus.c ft_free.c create_process.c
OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror -pthread#-fsanitize=address -g3 
NAME = philo_bonus

all : ${NAME}

${NAME}: ${OBJ}
	cc -o ${NAME} ${OBJ} ${CFLAGS}
clean :
	${RM} ${OBJ}
fclean : clean
	${RM} ${NAME}
re: fclean all
