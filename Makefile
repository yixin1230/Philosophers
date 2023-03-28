# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: yizhang <yizhang@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/16 11:41:56 by yizhang       #+#    #+#                  #
#    Updated: 2023/03/28 10:54:04 by yizhang       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = philosophers
CC = gcc
FLAG = -Wall -Werror -Wextra
SRC = main.c
OBJ = 

all: ${NAME}

${NAME}:
	${CC} ${FLAG} ${} -o ${NAME}

clean:

fclean:

re:

.PHONY: all clean fclean re bonus
