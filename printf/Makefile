CC = gcc

NAME = libftprintf.a

header = ft_printf.h

OBJ = ft_printf.o ft_printf_extra.o

BONES_OBJ = 

CFLAGS = -Wall -Werror -Wextra

ifdef plusbones
OBJ_FILES = $(OBJ) $(BONES_OBJ)
else
OBJ_FILES = $(OBJ)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar -crs $@ $^

%.o: %.c $(header)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ) $(BONES_OBJ)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

bonus:
	$(MAKE) plusbones=1 all

.PHONY: all clean fclean re bonus