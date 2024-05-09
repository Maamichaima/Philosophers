SRC = main.c inisialiser.c routine.c monitor.c check_bonus.c
OBJ = ${SRC:.c=.o}

# CFLAGS = -fsanitize=thread -g3#-Wall -Wextra -Werror 
NAME = philo

all : ${NAME}

${NAME}: ${OBJ}
	cc -o ${NAME} ${OBJ} ${CFLAGS}
clean :
	${RM} ${OBJ}
fclean : clean
	${RM} ${NAME}
re: fclean all
