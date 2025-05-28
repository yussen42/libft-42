NAME = libft.a

CC = cc
SRCS = ft_atoi.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	cc -Wall -Wextra -Werror -c $(SRCS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re fclean
