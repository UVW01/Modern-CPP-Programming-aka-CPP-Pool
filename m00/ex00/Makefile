# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 16:39:53 by mnaimi            #+#    #+#              #
#    Updated: 2022/07/26 11:44:54 by mnaimi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
CC			:= c++
CC_FLAGS	:= -Wall -Wextra -Werror -std=c++98

NAME		:= minishell
MAIN		:= minishell.c
HEADER		:= minishell.h

# ---------------------------------------------------------------------------- #
.PHONY: all clean fclean re title deps

all: ${NAME}

${NAME}: ${HEADER}
	@${CC} ${CC_FLAGS} ${MAIN} -o ${NAME} ${ARCHIVES}
	@echo "Executable ${NAME} created successfully :)\n"



clean:
	@

fclean: clean
	@rm -f ${NAME}
	@echo "${NAME} executable file has been deleted\n"

re: fclean all
