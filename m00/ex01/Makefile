# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 16:39:53 by mnaimi            #+#    #+#              #
#    Updated: 2022/08/09 10:36:09 by mnaimi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
CC			:= c++
CC_FLAGS	:= -Wall -Wextra -Werror -std=c++98

NAME		:= YellowBook
MAIN		:= ${NAME}.cpp
DEPS		:= PhoneBook.class.cpp Contact.class.cpp
HEAD		:= PhoneBook.class.hpp Contact.class.hpp

# ---------------------------------------------------------------------------- #
.PHONY: all clean re

all: ${NAME}

${NAME}: ${MAIN} ${HEAD}
	@${CC} ${CC_FLAGS} ${MAIN} ${DEPS} -o ${NAME}
	@echo "${NAME}: compiled successfully\n"

clean:
	@rm -f ${NAME}
	@echo "${NAME}: deleted successfully\n"

fclean: clean

re: clean all
