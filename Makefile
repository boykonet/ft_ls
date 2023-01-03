
NAME=ft_ls

CC=gcc

CFLAGS= -g -Wall -Wextra -Werror

SRCS=		./main.c \
#			./srcs/*.c

OBJS= $(SRCS:%.c=%.o)

HEADERS =	./headers/srcs.h \
			./headers/utils.h

INCLUDEDIR= ./

all: $(NAME)

$(NAME): $(OBJS) libft.a
	$(CC) $(CFLAGS) -I $(INCLUDEDIR) $^ -o $@

libft.a:
	$(MAKE) bonus -C ./libs/libft CC=$(CC)
	cp ./libs/libft/libft.a .

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I $(INCLUDEDIR) -c $< -o $@

clean:
	$(MAKE) clean -C ./libs/libft
	rm $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libs/libft
	rm -rf $(NAME) libft.a

re: fclean all

.PHONY: all clean fclean re
