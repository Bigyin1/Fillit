# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcadwyl <zcadwyl@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/02 19:15:31 by zcadwyl           #+#    #+#              #
#    Updated: 2019/02/02 20:14:08 by zcadwyl          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fillit 

SRC_DIR	:= ./fillit_p/
INC_DIR	:= -I./fillit_p -I./libft/includes
LIB = libft/libft.a

SRC		:= main.c \
		   reader.c \
		   solver.c \
		   map.c
SRCS	= $(patsubst %,$(SRC_DIR)%,$(SRC))
OBJ		= $(SRCS:.c=.o)

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror

all: $(LIB) $(NAME)

$(LIB):
	make -C libft all

$(SRC_DIR)%.o:$(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) -L libft/ -lft -o $(NAME)

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean

re: fclean all
