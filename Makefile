CC= gcc

NAME=so_long

OBJ= $(OBJ_path)so_main.o $(OBJ_path)so_map.o $(OBJ_path)char_list.o

ADDS= get_next_line/get_next_line.o get_next_line/get_next_line_utils.o $(print_path)libftprintf.a $(OBJ_path)so_checks.o

line_path= get_next_line/

OBJ_path= files/

print_path= printf/

header= $(line_path)get_next_line.h $(OBJ_path)so_long.h

CFLAGS= -Werror -Wall -Wextra -g

MLX= -Imlx -Lmlx -lmlx -framework OpenGL -framework Appkit

all:$(NAME)

start:$(NAME)
	./$(NAME) "map/test1.ber"

$(NAME): $(OBJ) $(ADDS)
	$(CC) -o $@ $^ $(MLX)

%.o: %.c $(header)
	$(CC) -c $(CFLAGS) -o $@ $<

%.a:
	make -C $(print_path)

clean:
	rm -f $(OBJ) $(ADDS)
	make -C $(print_path) clean

fclean: clean
	rm -f $(NAME)
	make -C $(print_path) fclean

re:
	$(MAKE) fclean
	$(MAKE) all

bonus:
	$(MAKE) plusbones=1 all

.PHONY: all clean fclean re bonus start