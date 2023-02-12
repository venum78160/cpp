GREEN = "\033[1;32m"
RED = "\033[1;31m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
WHITE = "\033[1;37m"
RESET = "\033[0m"

NAME = megaphone

FRONTNAME = MEGAPHONE

CC = c++

OBJECTS	= ./bin
 
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = megaphone.cpp \

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: ${NAME}

.c.o: $(SRCS)
	@printf $(GREEN)"\r\033[KCreating object files 👉 "$(YELLOW)"<$<> "$(RESET)
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	
${NAME}: ${OBJS}
		@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
		@printf $(GREEN)"\r\033[K✅ SUCCESS: "$(WHITE)$(FRONTNAME)$(GREEN)" has been created\n"$(RESET)

clean :

fclean: clean
		@${RM} ${NAME}
		@printf $(GREEN)"\r\033[K🗑️  Deleted: "$(WHITE)$(FRONTNAME)$(RED)" has been deleted\n"$(RESET)
		
re: fclean all

.PHONY: all clean fclean re readline