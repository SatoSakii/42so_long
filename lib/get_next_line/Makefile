CC = cc
FLAGS = -Wall -Wextra -Werror

SRCS = \
get_next_line.c \
get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
NAME = libgnl.a

all: $(NAME)

$(NAME) : $(OBJS)
	@ar -rc $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(FLAGS) -I./ -o $@ -c $<

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all
.PHONY: all clean fclean re
