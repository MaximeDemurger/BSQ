##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

name	= program

CC	= gcc

RM	= rm -f

SRCS	=

OBJS	= $(SCRS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
