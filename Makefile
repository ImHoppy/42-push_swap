EXEC	= push_swap

CC		= gcc
CFLAGS	= -Werror -Wall -Wextra -I$(INCLUDE)

LINKER	= gcc
LFLAGS	= -Werror -Wall -Wextra -I$(INCLUDE) -lm

RM		= rm -rf

LIBFT	= libft
INCLUDE	= includes/
SRC_DIR	= src
OBJ_DIR	= obj
SRC		= $(wildcard $(SRC_DIR)/*.c)
OBJ		= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


$(EXEC): $(OBJ)
	@make -C $(LIBFT) bonus
	$(CC) $(OBJ) $(LFLAGS) -L$(LIBFT) -lft -o $@
	@echo "\x1b[32mCompiled "$@" successfully! \x1b[0m"
#	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p ${OBJ_DIR}
	$(CC) $(CFLAGS) -I$(LIBFT) -c $< -o $@
	@echo "\x1b[34mCompiled "$<" successfully! \x1b[0m"


all: $(EXEC)

clean:
	${RM} $(OBJ_DIR)
fclean: clean
	${RM} $(EXEC)
re: fclean all

.PHONY: clean fclean all 