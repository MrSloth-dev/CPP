# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 09:59:30 by joao-pol          #+#    #+#              #
#    Updated: 2025/02/10 16:34:18 by joao-pol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
NAME = Forms
SRCS = main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
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
	valgrind -q --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY : all fclean re
