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

#NAME, all, clean, fclean, re

NAME = pipex

clean:

fclean: clean

re: fclean all

.phony : all clean fclean re
