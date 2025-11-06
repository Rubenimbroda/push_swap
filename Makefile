# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 11:21:07 by rnuno-im          #+#    #+#              #
#    Updated: 2025/11/06 12:30:16 by rnuno-im         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_sawp.a

CC		= cc
CFLAGS	= -Werror -Wextra -Wall

SRCS	= libf.a 

OBJS	= $(SRCS:.c=.o)

AR		= ar rcs
RM		= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re