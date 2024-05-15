SRC = main.c is_eating.c is_sleeping.c is_thinking.c routine.c inisialiser.c check_philo.c monitor.c ft_free.c create_threads.c check_arg.c
OBJ = ${SRC:.c=.o}

CFLAGS =  -Wall -Wextra -Werror -pthread#-fsanitize=address -g3 
NAME = philo

all : ${NAME}

${NAME}: ${OBJ}
	cc -o ${NAME} ${OBJ} ${CFLAGS}
clean :
	${RM} ${OBJ}
fclean : clean
	${RM} ${NAME}
re: fclean all
