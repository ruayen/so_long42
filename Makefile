NAME	= so_long
LIBMLX	= ./MLX
LIBFT	= ./libft
LIBPF	= ./printf
LIBGN	= ./get_next_line

HEADERS	= -I ./includes -I ${LIBMLX}/include -I ${LIBFT} -I ${LIBGN} -I ${LIBPF}
LIBGL	= -lglfw -L"/Users/raissaou/.brew/opt/glfw/lib"
LIBS	= ${LIBGL} ${LIBMLX}/libmlx42.a ${LIBFT}/libft.a ${LIBPF}/libftprintf.a ${LIBGN}/get_next_line.a
SRCS	= main.c \
			check_map.c \
			check_map_2.c \
			collectibles.c \
			images.c \
			map.c \
			move.c

OBJS	= ${SRCS:.c=.o}


all: libft libmlx libpf libgn ${NAME}

libft:
	@${MAKE} -C ${LIBFT}

libmlx:
	@${MAKE} -C ${LIBMLX}

libpf:
	@${MAKE} -C ${LIBPF}

libgn:
	@${MAKE} -C ${LIBGN}

%.o: %.c
	@${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

${NAME}: ${OBJS}
	@${CC} ${DFLAGS} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

clean:
	@rm -f ${OBJS}
	@${MAKE} -C ${LIBFT} clean
	@${MAKE} -C ${LIBMLX} clean
	@${MAKE} -C ${LIBPF} clean
	@${MAKE} -C ${LIBGN} clean

fclean: clean
	@rm -f ${NAME}
	@${MAKE} -C ${LIBFT} fclean
	@${MAKE} -C ${LIBMLX} fclean
	@${MAKE} -C ${LIBPF} fclean
	@${MAKE} -C ${LIBGN} fclean
	
re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft