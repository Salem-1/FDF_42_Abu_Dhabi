NAME =	fdf
SRC	=	parse_me.c projection.c bersenham.c mlx_operations.c  utils_fdf.c main.c more_utils.c

LDIR = mlx
CFLAGS =  -Wall -Wextra -Werror -Ofast
CC = gcc
OBJ	=	$(SRC:.c=.o)
LIBS = libft/libft.a printf/libftprintf.a ./libmlx.dylib 



all: $(NAME)
		 
$(NAME): comp_libs $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBS)  -framework OpenGL -framework AppKit

comp_libs:
	make -C ./mlx
	make -C libft/.
	make -C printf/.
	mv mlx/libmlx.dylib libmlx.dylib 

clean:
	rm -f *.o
	rm -f libmlx.dylib 
	make clean -C libft/.
	make clean -C printf/.
	make clean -C ./mlx


fclean: clean 
	@rm -f $(NAME) 
	@rm -f printf/printf.a
	@rm -f libft/libft.a
	@rm -f fdf
	
re: fclean all

# sand:	
# 	gcc -Lmlx -lmlx -framework OpenGL -framework AppKit open_window.c
# 	./a.out

# image:	
# 	gcc -Lmlx -lmlx -framework OpenGL -framework AppKit image.c
# 	./a.out

# test: re
# 	./fdf test_maps/42.fdf