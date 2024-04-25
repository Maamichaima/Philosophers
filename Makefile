SRC = main.c is_eating.c utils.c is_sleeping.c is_thinking.c routine.c
OBJ = ${SRC:.c=.o}

# CFLAGS =  -Wall -Wextra -Werror -fsanitize=thread
NAME = philo

all : ${NAME}

${NAME}: ${OBJ}
	cc -o ${NAME} ${OBJ}
clean :
	${RM} ${OBJ}
fclean : clean
	${RM} ${NAME}
re: fclean all
