# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/02 11:01:22 by frocha            #+#    #+#              #
#    Updated: 2024/11/02 11:01:24 by frocha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror

SRCS 	= pipex.c utils.c more_utils.c
OBJS 	= ${SRCS:.c=.o}

NAME = pipex

$(NAME): ${OBJS}
	@make re -C ./libft
	@$(CC) ${CFLAGS} ${OBJS} -Llibft -lft -o ${NAME}

all: $(NAME)

clean:
	@make clean -C ./libft
	@rm -f ${OBJS}

fclean: clean
	@make fclean -C ./libft
	@rm -f ${NAME}

re: fclean all

.phony : all clean fclean re
