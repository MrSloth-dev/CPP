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
	tmux send-keys "valgrind -q --vgdb-error=0 ./PmergeMe 132 63 62 200 98 40 44 151 14 171 106 212 126 52 163 116 39 186 194 173 30 123 114 196 27 214 35 109 91 68 102 86 162 83 204 20 206 99 139 182 141 66 136 69 38 36 215 42 167 105 211 199 130 111 4 187 26 89 95 64 153 71 15 169 198 21 177 78 175 208 203 81 87 67 3 58 23 5 195 55 190 54 43 101 185 61 201 183 184 122 90 170 178 202 18 172 189 100 82 73 180 51 72 121 159 207 13 96 115 161 10 112 25 133 118 29 12 144 17 47 209 74 124 113 174 16 104 129 45 33 110 131 59 70 125 168 213 50 181 191 85 152 150 140 142 22 157 145 135 158 56 160 179 65 164 137 1 117 31 80 188 79 46 57 24 108 148 7 77 92 192 166 19 32 154 37 11 2 6 76 197 41 210 103 94 97 119 134 9 75 147 143 146 165 156 8 93 193 28 53 120 128 176 84 49 107 127 34 60 138 88 149 48 205 155" C-m Escape
	tmux split-window -h
	sleep 1
	tmux send-keys -t vGdb.2 "gdb --tui --args ./PmergeMe 16 12 2 20 9 15 7 21 6 17 18 11 5 14 10 1 19 13 4 8 3" C-m
	tmux select-pane -t vGdb.1

asan : fclean
	$(CC) $(CFLAGS) $(ASANFLAGS) $(SRCS) -o $(NAME)
	./$(NAME) 0 1 2 3 4 5

va : re
	valgrind -q --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY : all fclean re vgdb
