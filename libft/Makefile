CC  	:= cc
CCFLAGS	:= -Wall -Wextra -Werror -c

SRCS := ft_lstclear.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_isfloat.c ft_isinteger.c ft_ternary.c ft_atof.c \
ft_pow.c ft_lstnew.c ft_strsub.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
get_next_line.c ft_itohexa.c ft_hexatoi.c ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memccpy.c ft_memcpy.c ft_putchar_fd.c ft_putstr_fd.c \
ft_strdup.c  ft_strlcpy.c ft_strncmp.c ft_strtrim.c ft_toupper.c ft_bzero.c ft_isalpha.c ft_isprint.c ft_memchr.c ft_memmove.c \
ft_putendl_fd.c ft_split.c ft_strjoin.c ft_strlen.c ft_strnstr.c ft_substr.c ft_calloc.c ft_isascii.c ft_itoa.c ft_memcmp.c ft_memset.c \
ft_putnbr_fd.c ft_strchr.c ft_strlcat.c ft_strmapi.c ft_strrchr.c ft_tolower.c ft_strcpy.c ft_strstr.c ft_strcmp.c ft_join.c ft_abs.c
TARGETS	:= libft.a
INCLUDES := -I./includes
SOURCES	:= $(addprefix srcs/, $(SRCS))
OBJECTS := $(SOURCES:.c=.o)

.c.o:
	$(CC) $(CCFLAGS) $(INCLUDES) $< -o ${<:.c=.o}

$(TARGETS) : $(OBJECTS)
	ar rcs $@ $^

clean:
	rm -f $(OBJECTS) $(BONUS:.c=.o)

fclean: clean
	rm -f $(TARGETS)

re: fclean all

all: $(TARGETS)
	
.PHONY: make clean fclean re