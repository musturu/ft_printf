NAME = libftprint.a

SRCS = printffone/*.c
LIBFT = libft

OUT = $(SRCS:.c=.o)

CC = gcc

all:
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT)/libft.a -L/$(LIBFT) -o $(NAME)

clean: fclean

fclean: clean
	make clean -C $(LIBFT)
	rm -rf $(NAME)

re: fclean all
