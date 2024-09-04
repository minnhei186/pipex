# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhosokaw <dhosokaw@student.42tokyo.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 13:49:56 by dhosokaw          #+#    #+#              #
#    Updated: 2024/09/04 11:33:12 by hosokawa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc 
CFLAGS=-Wall -Wextra -Werror -g
INCDIR=-Iinclude
LIBDIR=libft
SRCS=$(wildcard src/*.c)
OBJS=$(SRCS:.c=.o)

LIB_NAME=libft.a
NAME=pipex


all:$(LIB_NAME) $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS)	-L$(LIBDIR) -lft -o $@ $(OBJS) 

%.o: %.c
	$(CC) $(CFLAGS) $(INCDIR) -g -c $< -o $@

$(LIB_NAME):
	$(MAKE) -C $(LIBDIR)


clean:
	$(MAKE) clean -C $(LIBDIR)
	rm -rf $(OBJS)
fclean:clean
	$(MAKE) fclean -C $(LIBDIR)
	rm -f $(NAME)

re:fclean all

.PHONY:all clean fclean re
