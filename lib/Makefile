# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/28 13:09:12 by upolat            #+#    #+#              #
#    Updated: 2025/04/05 17:47:39 by upolat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libasm.a
SRC_DIR = .
OBJ_DIR = obj

SRC_FILES = ft_strlen.s ft_strcpy.s ft_strcmp.s \
			ft_write.s ft_read.s ft_strdup.s \
			ft_atoi.s ft_memcpy.s ft_memset.s

NASM     = nasm
# NASMFLAGS = -f macho64	# For Mac
NASMFLAGS = -f elf64	# For Linux

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.s=.o))

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s | $(OBJ_DIR)
	$(NASM) $(NASMFLAGS) -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
