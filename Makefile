NAME = fractol

FLAGS = -Wall -Wextra -Werror -I fractol.h

MLX = -lmlx -framework AppKit -framework OpenGl

LIB = ./libft/libft.a

SRC_FILES = 	main.c \
				mandelbrot.c \
				window.c \
				validation.c \
				errors.c \
				init_fract.c \
				events.c \
				
				


BIN_FILES = $(SRC_FILES:.c=.o)

all: makelib $(NAME)

makelib:
	make -C ./libft/

libclean:
	make -C ./libft/ clean

libfclean:
	make -C ./libft/ fclean

$(NAME): $(BIN_FILES)
	make -C ./libft/
	gcc -o $(NAME) $(BIN_FILES) $(FLAGS) $(MLX) $(LIB)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean: libclean
	/bin/rm -f $(BIN_FILES)

fclean: libfclean clean
	/bin/rm -f $(NAME)

re: fclean all