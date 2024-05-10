SRC = main.c inisialiser.c routine.c monitor.c check_bonus.c ft_free.c
OBJ = ${SRC:.c=.o}

# CFLAGS = -fsanitize=address#thread -g3#-Wall -Wextra -Werror 
NAME = philo

all : ${NAME}

${NAME}: ${OBJ}
	cc -o ${NAME} ${OBJ} ${CFLAGS}
clean :
	${RM} ${OBJ}
fclean : clean
	${RM} ${NAME}
re: fclean all
