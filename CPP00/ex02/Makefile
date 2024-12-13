CC = c++
NAME = account
SRCS = tests.cpp Account.cpp
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g
OBJS = $(SRCS:.cpp=.o)


all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

fclean :
	rm -fr $(NAME)

re : fclean all

va : re
	valgrind --leak-check=full ./acount

.PHONY : all fclean re
