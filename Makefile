# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnuno-im <rnuno-im@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 11:21:07 by rnuno-im          #+#    #+#              #
#    Updated: 2025/11/13 14:50:01 by rnuno-im         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	push_swap

CC		=	cc
CFLAGS	= 	-Werror -Wextra -Wall

LIBFT	=	./libft/libft.a

SRCS	=	cost.c imput_check_utils.c imput_check.c movements.c \
			p_operations.c positions.c push_swap.c r_operations.c \
			rr_operations.c s_operations.c sort_big.c sort_small.c \
			stack_utils.c utils.c utils_2.c utils_3.c

OBJS	= $(SRCS:.c=.o)

AR		= ar rcs
RM		= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "✅ Compilation complete: $(NAME)"
	
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)
	@echo "🧹 Object files cleaned."

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
	@echo "🗑️  All cleaned (including binary)."

re: fclean all

.PHONY: all clean fclean re