
NAME = ft_ls

SRCS =	src/main.c \
		src/ft_ls.c \
		src/rsio.c \
		src/set_args.c \
		src/display.c \
		src/compare_func.c \
		src/nbr_utils.c \
		src/print_utils1.c \
		src/print_utils2.c \
		src/specialperm.c

OBJ =	main.o \
		ft_ls.o \
		rsio.o \
		set_args.o \
		display.o \
		compare_func.o \
		nbr_utils.o \
		print_utils1.o \
		print_utils2.o \
		specialperm.o

all: $(NAME)

$(NAME):
	make -C libft/ fclean
	make -C libft/
	gcc -Wall -Werror -Wextra -I libft/ -I includes/ -c $(SRCS)
	gcc -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	/bin/rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
