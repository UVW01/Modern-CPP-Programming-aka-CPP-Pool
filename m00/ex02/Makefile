# **************************************************************************** #
#                                                                              #
#   /$$      /$$ /$$$$$$ /$$   /$$/$$$$$$$$/$$$$$$$$/$$$$$$/$$      /$$$$$$$$  #
#  | $$$    /$$$/$$__  $| $$  /$$| $$_____| $$_____|_  $$_| $$     | $$_____/  #
#  | $$$$  /$$$| $$  \ $| $$ /$$/| $$     | $$       | $$ | $$     | $$        #
#  | $$ $$/$$ $| $$$$$$$| $$$$$/ | $$$$$  | $$$$$    | $$ | $$     | $$$$$     #
#  | $$  $$$| $| $$__  $| $$  $$ | $$__/  | $$__/    | $$ | $$     | $$__/     #
#  | $$\  $ | $| $$  | $| $$\  $$| $$     | $$       | $$ | $$     | $$        #
#  | $$ \/  | $| $$  | $| $$ \  $| $$$$$$$| $$      /$$$$$| $$$$$$$| $$$$$$$$  #
#  |__/     |__|__/  |__|__/  \__|________|__/     |______|________|________/  #
#                                                                              #
# **************************************************************************** #

RST			:= \e[0m
RED			:= \e[31m
GRN			:= \e[32m
CYN			:= \e[36m

CC			:= c++
CC_FLAGS	:= -Wall -Wextra -Werror -std=c++98

NAME		:= TestResult
MAIN		:= tests.cpp
SRCS		:= Account.cpp
OBJS		:= ${SRCS:%.cpp=%.obj}
HEAD		:= Account.hpp

define print_status
    @printf "%21s $2$3 successfully${RST}\n" "$1 :"
endef

# ---------------------------------------------------------------------------- #

.PHONY: all clean fclean re

all: ${NAME}

${NAME}: ${OBJS} ${MAIN} ${HEAD}
	@${CC} ${CC_FLAGS} ${MAIN} ${OBJS} -o ${NAME}
	$(call print_status, ${NAME}, ${GRN}, "compiled")

%.obj: %.cpp ${HEAD}
	@${CC} ${CC_FLAGS} -c $< -o $@
	$(call print_status, $@, ${CYN}, "created")

build:
	@make fclean
	@make all

clean:
	@rm -f ${OBJS}
	$(call print_status, "*.obj", ${RED}, "deleted")

fclean: clean
	@rm -f ${NAME}
	$(call print_status, ${NAME}, ${RED}, "deleted")

re: fclean all

