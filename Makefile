NAME = cub3d

_SRCS = main.c errors.c parser_frame.c  parser_routines.c  reader.c angles_basic.c utils_parser.c

SRCS = $(addprefix srcs/, $(_SRCS))
SRCO = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror
INC = -I includes/

all : $(NAME)

sanitize : $(SRCO)
	make -C libft
	cc -o $(NAME) $(SRCO) libft/libft.a -fsanitize=address

$(NAME) : $(SRCO)
	make -C libft
	cc -o $(NAME) $(SRCO) libft/libft.a

%.o : %.c
	cc $(FLAG) -o $(NAME) -c $< -o $@ $(INC)

clean :
	/bin/rm -f $(SRCO)
	make clean -C libft

fclean : clean
	/bin/rm -f $(NAME)
	/bin/rm -f libft/libft.a

re : fclean all

rcl : re
	make clean

.PHONY: make clean fclean re rcl sanitize
