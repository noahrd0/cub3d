# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -Imlx_linux -I/usr/include -I/usr/include/X11 -I$(INC_DIR) -I$(LIBFT_DIR)/includes

# Linker flags
LDFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -L$(LIBFT_DIR) -lft

# Directories
SRC_DIR = srcs
SRC_DIR_BONUS = srcs_bonus
OBJ_DIR = objs
OBJ_DIR_BONUS = objs_bonus
INC_DIR = includes

# Header
HEADER = $(INC_DIR)/cub3d.h
HEADER_BONUS = $(INC_DIR)/cub3d_bonus.h
HEADER_GNL = get_next_line/get_next_line.h

# Sources (main)
SRCS = $(wildcard $(SRC_DIR)/**/*.c) $(wildcard $(SRC_DIR)/*.c) get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
NAME = cub3d

# Sources (bonus)
SRCS_BONUS = $(wildcard $(SRC_DIR_BONUS)/**/*.c) $(wildcard $(SRC_DIR_BONUS)/*.c) get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJS_BONUS = $(patsubst $(SRC_DIR_BONUS)/%.c, $(OBJ_DIR_BONUS)/%.o, $(SRCS_BONUS))
BONUS_NAME = cub3d_bonus

# Libft
LIBFT_DIR = libft
LIBFT_MAKE = $(MAKE) -C $(LIBFT_DIR) -s
LIBFT_HEADER = $(LIBFT_DIR)/includes/libft.h
LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/src/*.c)
LIBFT_OBJS = $(patsubst $(LIBFT_DIR)/src/%.c, $(LIBFT_DIR)/objs/%.o, $(LIBFT_SRCS))
LIBFT = $(LIBFT_DIR)/libft.a

# Colors
RESET = \033[0m
GREEN = \033[32m
YELLOW = \033[33m
WHITE = \033[37m

.PHONY: all clean fclean re bonus libft

all: $(NAME)

FORCE:

$(LIBFT): $(LIBFT_SRCS) $(LIBFT_HEADER)
	@$(MAKE) -C $(LIBFT_DIR) -s

$(NAME): $(LIBFT) $(OBJS)
	@$(MAKE) -C mlx_linux -s
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@
	@echo "$(GREEN)[$(NAME)]$(RESET) $@ created."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) $(HEADER_GNL) $(LIBFT_HEADER)
	@mkdir -p $(OBJ_DIR)/$(dir $*)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)[$(NAME)]$(RESET) $@ created."

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(OBJS_BONUS)
	@$(MAKE) -C mlx_linux -s
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LDFLAGS) -o $@
	@echo "$(YELLOW)[$(BONUS_NAME)]$(RESET) $@ created."

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c $(HEADER_BONUS) $(HEADER_GNL) $(LIBFT_HEADER)
	@mkdir -p $(OBJ_DIR_BONUS)/$(dir $*)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)[$(BONUS_NAME)]$(RESET) $@ created."

clean:
	@$(RM) -r $(OBJ_DIR) $(OBJ_DIR_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean -s
	@$(MAKE) -C mlx_linux -s clean
	@echo "$(GREEN)[$(NAME)]$(RESET) $@ .o files deleted."

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean -s
	@echo "$(GREEN)[$(NAME)]$(RESET) $@ .o files deleted."

re: fclean all
