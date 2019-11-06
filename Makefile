NAME	= program

CC	= gcc

RM	= rm -f

SRCS	= ./src/bsq.c \
	  ./src/main.c \
	  ./src/my_str_to_word_array.c \
	  ./src/put_in_tab.c \
	  ./src/printing_square.c \
	  ./src/my_strdup.c \
	  ./src/my_strlen.c \
	  ./src/my_strcpy.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
