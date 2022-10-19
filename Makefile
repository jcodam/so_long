CC= gcc

NAME=so_long

OBJ= $(OBJ_path)so_main.o $(OBJ_path)so_map.o $(OBJ_path)char_list.o $(OBJ_path)so_checks.o $(OBJ_path)so_extra.o

ADDS= get_next_line/get_next_line.o get_next_line/get_next_line_utils.o $(print_path)libftprintf.a mlx/libmlx.a

line_path= get_next_line/

OBJ_path= files/

print_path= printf/

header= $(line_path)get_next_line.h $(OBJ_path)so_long.h $(print_path)ft_printf.h

CFLAGS= -Werror -Wall -Wextra -g

MLX= -Imlx -Lmlx -lmlx -framework OpenGL -framework Appkit

all:$(NAME)

smal:$(NAME)
	./$(NAME) "map/smal_map.ber"

mediam:$(NAME)
	./$(NAME) "map/mediam_map.ber"

big:$(NAME)
	./$< "map/big_map.ber"

invalid:$(NAME)
	./$< "map/no_ber"
	./$< "map/no_exit.ber"
	./$< "map/no_sluge.ber"
	./$< "map/no_player.ber"
	./$< "map/can't_reach_exit.ber"
	./$< "this_not_a_file.ber"
	./$< "map/big_map.ber" "map/smal_map.ber"
	./$<

$(NAME): $(OBJ) $(ADDS)
	$(CC) -o $@ $^ $(MLX)

%.a:
	@$(MAKE) -C $(print_path)
	@$(MAKE) -C mlx/

%.o: %.c $(header)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ) $(ADDS)
	$(MAKE) -C $(print_path) clean
	$(MAKE) -C mlx/ clean

fclean:
	rm -f $(NAME) $(OBJ) $(ADDS)
	$(MAKE) -C $(print_path) fclean

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re smal mediam big invalid