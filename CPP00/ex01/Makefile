# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 09:59:30 by joao-pol          #+#    #+#              #
#    Updated: 2024/12/03 10:07:25 by joao-pol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
NAME = phonebook
SRCS = main.cpp contact.cpp phonebook.cpp utils.cpp
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g
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

va : re
	valgrind --leak-check=full --show-leak-kinds=all ./phonebook

.PHONY : all fclean re
