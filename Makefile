NAME = cub3d

_SRCS_GFX = algorithm.c window.c raycasting.c graphics.c movements.c
_SRCS_BASIC = main.c errors.c angles_basic.c freedom.c utils.c debug.c filling.c filling_utils.c parser_frame.c parser_map.c \
parser_routines.c parser_utils.c reader.c

SRCS_GFX = $(addprefix srcs/, $(_SRCS_GFX))
SRCS_BASIC = $(addprefix srcs/, $(_SRCS_BASIC))

SRCO_GFX = $(SRCS_GFX:.c=.o)
SRCO_BASIC = $(SRCS_BASIC:.c=.o)

FLAG = -g -Wall -Wextra -Werror
INC = -I includes/

all : $(NAME)

mlx : $(SRCO_BASIC) $(SRCO_GFX)
	make -C libft
	cc -o $(NAME) $(SRCO_BASIC) $(SRCO_GFX) -Lmlx -lmlx -framework OpenGL -framework AppKit libft/libft.a

no_gfx : $(SRCO_BASIC)
	make -C libft
	cc -o $(NAME) $(SRCO_BASIC) libft/libft.a

no_gfx_sanitize : $(SRCO_BASIC)
	make -C libft
	cc -o $(NAME) $(SRCO_BASIC) libft/libft.a -fsanitize=address

%.o : %.c
	cc $(FLAG) -Imlx -o $(NAME) -c $< -o $@ $(INC)

clean :
	/bin/rm -f $(SRCO_GFX) $(SRCO_BASIC)
	make clean -C libft

fclean : clean
	/bin/rm -f $(NAME)
	/bin/rm -f libft/libft.a

re : fclean all

rcl : re
	make clean

.PHONY: make clean fclean re rcl sanitize mlx no_gfx