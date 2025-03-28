# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/28 13:10:35 by upolat            #+#    #+#              #
#    Updated: 2025/03/28 19:24:54 by upolat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = test_program
LIB_DIR = lib
LIB     = $(LIB_DIR)/libasm.a
SRC     = main.c
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

all: $(NAME)

# First one for Mac, second one for Linux
$(NAME): $(SRC) $(LIB)
#	$(CC) -arch x86_64 $(CFLAGS) -o $(NAME) $(SRC) $(LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIB)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

clean:
	$(MAKE) -C $(LIB_DIR) clean

fclean:
	$(MAKE) -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
