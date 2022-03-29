EXEC	= push_swap

CC		= cc
CFLAGS	= -Werror -Wall -Wextra -I$(INCLUDE) -g

LINKER	= cc
LFLAGS	= -Werror -Wall -Wextra -I$(INCLUDE) -g

RM		= rm -rf

LIBFT	= libft
LIBFT_M	= ${MAKE} -C ${LIBFT}/
INCLUDE	= includes/
SRC_DIR	= src
OBJ_DIR	= obj
SRC		= src/algo.c  src/algo_small.c  src/operations.c  src/operations_rotate.c  src/push_swap.c  src/radix.c  src/stack.c  src/stacks_utils.c  src/stacks_utils2.c  src/utils.c
OBJ		= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	COLOR = \033
endif
ifeq ($(UNAME_S),Darwin)
	COLOR = \x1b
endif

$(EXEC): $(OBJ)
	@${LIBFT_M} bonus
	$(CC) $(OBJ) $(LFLAGS) -L$(LIBFT) -lft -o $@
	@printf "$(COLOR)[32mCompiled "$@" successfully! $(COLOR)[0m\n"
#	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p ${OBJ_DIR}
	$(CC) $(CFLAGS) -I$(LIBFT) -c $< -o $@
	@printf "$(COLOR)[34mCompiled "$<" successfully! $(COLOR)[0m\n"


all: $(EXEC)

clean:
	${LIBFT_M} clean
	${RM} $(OBJ_DIR)
	
fclean: clean
	${LIBFT_M} fclean
	${RM} $(EXEC)
re: fclean all

.PHONY: clean fclean all 
