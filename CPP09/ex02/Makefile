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
CC_DEBUG = g++
NAME = PmergeMe
SRCS = main.cpp PmergeMe.cpp
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g
ASANFLAGS = -fsanitize=address -fsanitize=leak -fsanitize=undefined -fno-omit-frame-pointer
OBJS = $(SRCS:.cpp=.o)
CHECKER=checker


all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

debug : fclean
	$(CC_DEBUG) $(CFLAGS) $(SRCS) -o $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -fr *.o

fclean : clean
	rm -fr $(NAME)
	rm -fr $(CHECKER)

re : fclean all

.PHONY: gdb
gdb : re
	tmux set-option remain-on-exit off
	tmux new-window  -n Gdb
	tmux send-keys 'gdb --tui --args ./PmergeMe 16 12 2 20 9 15 7 21 6 17 18 11 5 14 10 1 19 13 4 8 3' C-m Escape
	tmux split-window -h -l 30
	tmux send-keys -t Gdb.2 'nvim .gdbinit' C-m
	tmux select-pane -t Gdb.1

vgdb : re
	tmux new-window  -n vGdb
	tmux send-keys "valgrind -q --vgdb-error=0 ./PmergeMe `shuf -i 1-11`" C-m Escape
	tmux split-window -h
	sleep 1
	tmux send-keys -t vGdb.2 "gdb --tui --args ./PmergeMe 16 12 2 20 9 15 7 21 6 17 18 11 5 14 10 1 19 13 4 8 3" C-m
	tmux select-pane -t vGdb.1

asan : fclean
	$(CC) $(CFLAGS) $(ASANFLAGS) $(SRCS) -o $(NAME)
	shuf -i 1-11 | xargs ./$(NAME)

va : re
	valgrind -q --leak-check=full --show-leak-kinds=all ./$(NAME)

checker: checker.cpp
	rm -fr $(CHECKER)
	$(CC) $(CFLAGS) checker.cpp -o $(CHECKER)

.PHONY : all fclean re vgdb
.SILENT: fclean re clean
