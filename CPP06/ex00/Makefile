# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 09:59:30 by joao-pol          #+#    #+#              #
#    Updated: 2025/02/03 14:00:03 by joao-pol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
NAME = convert
SRCS = main.cpp ScalarConverter.cpp
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g
ASANFLAGS = -fsanitize=address -fsanitize=leak -fsanitize=undefined -fno-omit-frame-pointer
OBJS = $(SRCS:.cpp=.o)


all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -fr *.o

fclean : clean
	rm -fr $(NAME)

re : fclean all

asan : fclean
	$(CC) $(CFLAGS) $(ASANFLAGS) $(SRCS) -o $(NAME)
	./$(NAME)

va : re
	valgrind -q --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY : all fclean re
