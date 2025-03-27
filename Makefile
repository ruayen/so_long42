NAME            = so_long

CC              = cc
CFLAGS          = -Wall -Wextra -Werror
LIBFT           = ./libft
MLX42           = ./MLX42/build
FT_PRINTF       = ./ft_printf
INCLUDES        = -I$(MLX42)/include -I$(LIBFT)/include -I$(FT_PRINTF)/include -Iincludes
LIBS            = -L$(MLX42) -lmlx42 -lglfw -lX11 -lXext -lm -lpthread -L$(LIBFT) -lft -L$(FT_PRINTF) -lftprintf

SRC_DIR         = ./srcs
OBJ_DIR         = ./obj

SRC_FILES       = main.c \
                  check_map.c \
                  check_map2.c \
                  coins.c \
                  images.c \
                  map.c \
                  moves.c

OBJS            = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

$(LIBFT)/libft.a:
	@$(MAKE) -C $(LIBFT)

$(FT_PRINTF)/libftprintf.a:
	@$(MAKE) -C $(FT_PRINTF)

all:    $(NAME)

clean:
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(FT_PRINTF) clean
	@rm -r $(OBJ_DIR)

fclean: clean
	@rm $(NAME)
	@rm $(LIBFT)/libft.a
	@rm $(FT_PRINTF)/libftprintf.a

re: fclean all

.PHONY: all clean fclean re
