
LIB = -lreadline

LIBFT_DIR         = libft/
LIBFT             = libft.a
NAME              = minishell
CC                = clang
CFLAGS            = -Wall -Werror -Wextra -Iincludes -g -Iinclude
RM                = rm -rf

SRC_DIR           = src/
OBJ_DIR           = obj/

FILES_SRC         = main.c built_ins.c function_env.c parser.c main_exeggutor.c\
					export.c unset.c exeggutor.c

SRC               = $(addprefix $(SRC_DIR),$(FILES_SRC))
OBJ_SRC           = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

MAKEFLAGS += s

vpath %.c $(SRC_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	
all: $(NAME)

$(NAME): $(OBJ_SRC)
	@$(MAKE) -s all bonus printf gnl -C $(LIBFT_DIR)
	$(CC) $(OBJ_SRC) ${INCS} ${LIB} -L$(LIBFT_DIR) -lft -o $@

clean:
	@$(RM) $(OBJ_DIR)
	
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re