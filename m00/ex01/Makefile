# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 16:39:53 by mnaimi            #+#    #+#              #
#    Updated: 2022/08/01 14:08:15 by mnaimi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
CC			:= c++
CC_FLAGS	:= -Wall -Wextra -Werror -std=c++98

NAME		:= main
MAIN		:= ${NAME}.cpp

# ---------------------------------------------------------------------------- #
.PHONY: all clean re

all: ${NAME}

${NAME}: ${MAIN}
	@${CC} ${CC_FLAGS} ${MAIN} -o ${NAME}
	@echo "${NAME}: compiled successfully\n"

clean:
	@rm -f ${NAME}
	@echo "${NAME}: deleted successfully\n"

re: clean all
