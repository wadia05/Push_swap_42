NAME = push_swap

HDER = mandatory/push_swap.h

SRC = \
	mandatory/input_chek_v2.c\
	mandatory/list_tools.c\
	mandatory/push_swap.c\
	mandatory/move.c\
	mandatory/sort.c\
	mandatory/index.c\
	mandatory/range.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ) $(HDER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all