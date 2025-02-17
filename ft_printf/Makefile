NAME=libftprintf.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
SOURCES =	ft_printf.c \
			ft_printf_pointer.c \
			ft_printf_basics.c \
			ft_printf_hexadecimal.c
OBJECTS=$(SOURCES:.c=.o)
all: $(NAME)
$(NAME): $(OBJECTS)
	ar rcs $@ $?
%.o: %.c
	$(CC) -c $(CFLAGS) $?
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all