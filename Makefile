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

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	COLOR = \033
endif
ifeq ($(UNAME_S),Darwin)
	COLOR = \x1b
endif

$(EXEC): $(OBJ)
	@make -C $(LIBFT) bonus
	$(CC) $(OBJ) $(LFLAGS) -L$(LIBFT) -lft -o $@
	@echo "$(COLOR)[32mCompiled "$@" successfully! $(COLOR)[0m"
#	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p ${OBJ_DIR}
	$(CC) $(CFLAGS) -I$(LIBFT) -c $< -o $@
	@echo "$(COLOR)[34mCompiled "$<" successfully! $(COLOR)[0m"


all: $(EXEC)

clean:
	${RM} $(OBJ_DIR)
fclean: clean
	${RM} $(EXEC)
re: fclean all

.PHONY: clean fclean all 