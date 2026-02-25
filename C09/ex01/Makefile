# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adraji <adraji@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/06 03:57:21 by adraji            #+#    #+#              #
#    Updated: 2025/12/15 08:40:49 by adraji           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCDIR  = srcs
INCDIR  = includes

NAME    = libft.a

SRC     = $(SRCDIR)/ft_putchar.c \
          $(SRCDIR)/ft_swap.c \
          $(SRCDIR)/ft_putstr.c \
          $(SRCDIR)/ft_strlen.c \
          $(SRCDIR)/ft_strcmp.c

OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
