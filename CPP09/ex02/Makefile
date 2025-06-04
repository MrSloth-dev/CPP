# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 09:59:30 by joao-pol          #+#    #+#              #
#    Updated: 2025/02/24 22:31:26 by joao-pol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
NAME = PmergeMe
SRCS = main.cpp PmergeMe.cpp
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean :
	rm -fr *.o

fclean : clean
	rm -fr $(NAME)

re : fclean all

.PHONY : all fclean re
.SILENT: fclean re clean
