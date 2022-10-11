CC= gcc

NAME=so_long

OBJ= $(OBJ_path)so_main.o $(OBJ_path)so_map.o $(OBJ_path)char_list.o

ADDS= get_next_line/get_next_line.o get_next_line/get_next_line_utils.o

line_path= get_next_line/

OBJ_path= files/

header= $(line_path)get_next_line.h $(OBJ_path)so_long.h

CFLAGS= -Werror -Wall -Wextra

all:$(NAME)

start:$(NAME)
	./$(NAME) "map/test1.ber"

$(NAME): $(OBJ) $(ADDS)
	$(CC) -o $@ $^

%.o: %.c $(header)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ) $(ADDS)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

bonus:
	$(MAKE) plusbones=1 all

.PHONY: all clean fclean re bonus start