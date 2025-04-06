NAME := libft.a

CC:=cc
HFILES = ./
CFLAGS:= -Wall -Wextra -Werror
CPPFLAGS:= -I
SRC=./ft_atoi.c\
    ./ft_split.c\
    ./ft_isdigit.c\
    ./ft_strlen.c\
    ./ft_strlcpy.c\

OBJ:=$(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I ./ -c -o $@ $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean
	make all

.PHONY: all clean fclean re
