# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: gkarina <gkarina@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/05 14:23:57 by gkarina       #+#    #+#                  #
#    Updated: 2023/05/05 14:23:57 by gkarina       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME=ft_ls
CC=clang
CFLAGS= -g -Wall -Wextra -Werror -fsanitize=address

SRCS=	./main.c \
		./srcs/set/filemode.c \
		./srcs/set/filetype.c \
		./srcs/set/group.c \
		./srcs/set/link.c \
		./srcs/set/number_of_bytes.c \
		./srcs/set/number_of_links.c \
		./srcs/set/owner.c \
		./srcs/set/time.c \
		./srcs/dir.c \
		./srcs/execute.c \
		./srcs/fileinfo.c \
		./srcs/flag.c \
		./srcs/ls_func.c \
		./srcs/parse.c \
		./srcs/print.c \
		./srcs/quick_sort.c \
		./srcs/readlink.c \
		./srcs/sort.c \
		./srcs/spaces.c \
		./utils/calloca_to_2d.c \
		./utils/color.c \
		./utils/copy.c \
		./utils/double_array_utils.c \
		./utils/error.c \
		./utils/is_more_less.c \
		./utils/isatty.c \
		./utils/max.c \
		./utils/pattern.c \
		./utils/rec_itoa.c \
		./utils/rec_putnbr.c \
		./utils/strmode.c

OBJS= $(SRCS:%.c=%.o)

HEADERS =	./ls.h \
			./libs/libft/libft.h

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
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libs/libft
	rm -rf $(NAME) libft.a

re: fclean all

run:
	ASAN_OPTIONS=detect_leaks=1 ./$(NAME)

.PHONY: all clean fclean re run
