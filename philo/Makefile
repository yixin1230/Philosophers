# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: yizhang <yizhang@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/16 11:41:56 by yizhang       #+#    #+#                  #
#    Updated: 2023/06/06 09:22:33 by yizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
FLAG = -Wall -Werror -Wextra -g3 #-fsanitize=thread
SRC = main.c initualize.c actions.c checker.c monitor.c
OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}:${OBJ}
	${CC} ${FLAG} ${OBJ} -o ${NAME}

${OBJ}:${SRC}
	@${CC} ${FLAGS} -c ${SRC}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
