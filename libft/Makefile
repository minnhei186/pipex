
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCDIR=include
SRCS =$(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)
Library= ar rc
NAME = libft.a

all : $(NAME)

$(NAME):$(OBJS)
	$(Library) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all 

.PHONY: all clean fclean re
