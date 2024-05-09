SRC = main.c is_eating.c is_sleeping.c is_thinking.c routine.c inisialiser.c check.c monitor.c ft_free.c create_threads.c
OBJ = ${SRC:.c=.o}

CFLAGS =  -Wall -Wextra -Werror #-fsanitize=thread -g3 
NAME = philo

all : ${NAME}

${NAME}: ${OBJ}
	cc -o ${NAME} ${OBJ} ${CFLAGS}
clean :
	${RM} ${OBJ}
fclean : clean
	${RM} ${NAME}
re: fclean all
