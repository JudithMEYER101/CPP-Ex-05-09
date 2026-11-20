# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 10:21:22 by armeyer           #+#    #+#              #
#    Updated: 2025/04/07 12:13:05 by armeyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98  

NAME = Mutant

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re