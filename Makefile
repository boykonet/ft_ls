
NAME=ft_ls

CC=gcc

CFLAGS= -g -Wall -Wextra -Werror

SRCS=		./main.c \
			./srcs/dir.c \
			./srcs/execute.c \
			./srcs/get_file_info.c \
			./srcs/ls_functions.c \
			./srcs/lstat.c \
			./srcs/parse.c \
			./srcs/readlink.c \
			./srcs/sort.c \
			./utils/calloca_to_2d.c \
			./utils/copy.c \
			./utils/double_array_utils.c \
			./utils/error.c \
			./utils/pattern.c \
			./utils/printer.c

OBJS= $(SRCS:%.c=%.o)

HEADERS =	./ls.h

INCLUDEDIR= ./

all: $(NAME)

$(NAME): $(OBJS) libft.a
	$(CC) $(CFLAGS) -I $(INCLUDEDIR) $^ -o $@

libft.a:
	$(MAKE) -C ./libs/libft CC=$(CC)
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
