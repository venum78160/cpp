CC			= c++ -Wall -Wextra -Werror -std=c++98
RM			= rm -rf
NAME		= ./brain
NAME_SHORT	= BRAIN

SRCS		= main.cpp

OBJS		= $(SRCS:.cpp=.o)

_COLOR		= \033[32m
_BOLDCOLOR	= \033[32;1m
_RESET		= \033[0m
_CLEAR		= \033[0K\r\c
_OK			= [\033[32mOK\033[0m]

%.o			: %.cpp
			@echo "[..] $(NAME_SHORT)... compiling $*.cpp\r\c"
			@$(CC) -c $< -o $@
			@echo "$(_CLEAR)"

all			: $(NAME)

$(NAME)		: $(OBJS)
			@$(CC) $(OBJS) -o $(NAME)
			@echo "$(_OK) $(NAME_SHORT) compiled"

clean		:
			@$(RM) $(OBJS)

fclean		: clean
			@$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re