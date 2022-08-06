NAME =	fdf.a
SRC	=	gnl/get_next_line.c  gnl/get_next_line_utils.c \
parse_me.c projection.c

LDIR = mlx
CFLAGS =  -Wall -Wextra -Werror
CC = gcc
OBJ	=	$(SRC:.c=.o)



$(NAME):	$(OBJ)
	ar -rcs $(NAME) $(OBJ)
	
all: $(NAME)
	ar -rcs $(NAME) $(OBJ)
	make -C printf/.
	make -C libft/.
	mv libft/libft.a libft.a
	mv printf/libftprintf.a printf.a 
	#	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	#$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)	
	
clean:
	rm -f *.o
	rm -f gnl/*.o
	make clean -C libft/.
	make clean -C printf/.


fclean: clean 
	@rm -f $(NAME) 
	@rm -f printf.a
	@rm -f libft.a
	@rm -f fdf
	
re: fclean all

sand:	
	gcc -Lmlx -lmlx -framework OpenGL -framework AppKit open_window.c
	./a.out

image:	
	gcc -Lmlx -lmlx -framework OpenGL -framework AppKit image.c
	./a.out

test: re
	gcc fdf.a printf.a libft.a main.c -o fdf
	./fdf test_maps/42.fdf