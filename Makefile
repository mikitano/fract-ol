# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/22 18:15:28 by mkitano           #+#    #+#              #
#    Updated: 2025/11/29 14:51:59 by mkitano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
EXEC = $(BIN_DIR)/$(NAME)

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include

LIBFT_DIR = lib/libftx
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = lib/mlx
MLX = $(MLX_DIR)/libmlx.a

SRC_FILES = main.c \
		init.c \
		render.c \
		math_utils.c \
		events.c \
		string_utils.c \

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
HEADERS = $(addprefix $(INCLUDE_DIR)/, fractol.h)
DEPS = $(OBJS:.o=.d)

CC = cc
AR = ar
ARFLAGS = crs

CCFLAGS = -Wall -Wextra -Werror -g
DEPFLAGS = -MMD -MP
IFLAGS = -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/include -I$(MLX_DIR)
LDFLAGS = -L$(LIBFT_DIR) -L$(MLX_DIR)
LDLIBS := -lft -lmlx -lXext -lX11 -lm -lz

RM = rm
RMFLAGS = -rf

all: $(MLX) $(LIBFT) $(EXEC)
		@echo ""
		@echo "███████╗██████╗░░█████╗░░█████╗░████████╗░█████╗░██╗░░░░░"
		@echo "██╔════╝██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗██║░░░░░"
		@echo "█████╗░░██████╔╝███████║██║░░╚═╝░░░██║░░░██║░░██║██║░░░░░"
		@echo "██╔══╝░░██╔══██╗██╔══██║██║░░██╗░░░██║░░░██║░░██║██║░░░░░"
		@echo "██║░░░░░██║░░██║██║░░██║╚█████╔╝░░░██║░░░╚█████╔╝███████╗"
		@echo "╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░░╚════╝░╚══════╝"
		@echo ""

-include $(DEPS)

$(LIBFT) :
		@echo "[\033[0;33m...\033[0m] CREATING libft..."
		@$(MAKE) -C $(LIBFT_DIR) --silent

$(MLX):
		@echo "[\033[0;33m...\033[0m] CREATING MiniLibX..."
		@$(MAKE) -C $(MLX_DIR) --silent

$(EXEC) : $(OBJS)
		@mkdir -p $(BIN_DIR)
		@$(CC) $(CCFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(EXEC)
		@echo "[\033[0;32mOK\033[0m] $(NAME) COMPILED in $(BIN_DIR)/!"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HEADERS)
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CCFLAGS) $(IFLAGS) $(DEPFLAGS) -c $< -o $@
		@echo "[\033[0;32mOK\033[0m] COMPILED $<"

$(BIN_DIR) $(OBJ_DIR):
	@mkdir -p $@

clean :
		@$(RM) $(RMFLAGS) $(OBJ_DIR)
		@$(MAKE) -C $(LIBFT_DIR) clean --silent
		@$(MAKE) -C $(MLX_DIR) clean --silent
		@echo "[\033[0;32mOK\033[0m] CLEAR files!"

fclean : clean
		@$(RM) $(RMFLAGS) $(BIN_DIR)
		@$(MAKE) -C $(LIBFT_DIR) fclean --silent
		@echo "[\033[0;32mOK\033[0m] ALL CLEAR!"
		@echo ""
		@echo "⠀⠀⢀⣀⠤⠿⢤⢖⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		@echo "⡔⢩⠂⠀⠒⠗⠈⠀⠉⠢⠄⣀⠠⠤⠄⠒⢖⡒⢒⠂⠤⢄⠀⠀⠀⠀"
		@echo "⠇⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠈⠀⠈⠈⡨⢀⠡⡪⠢⡀⠀"
		@echo "⠈⠒⠀⠤⠤⣄⡆⡂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠢⠀⢕⠱⠀"
		@echo "⠀⠀⠀⠀⠀⠈⢳⣐⡐⠐⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠁⠇"
		@echo "⠀⠀⠀⠀⠀⠀⠀⠑⢤⢁⠀⠆⠀⠀⠀⠀⠀⢀⢰⠀⠀⠀⡀⢄⡜⠀"
		@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠘⡦⠄⡷⠢⠤⠤⠤⠤⢬⢈⡇⢠⣈⣰⠎⠀⠀"
		@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣃⢸⡇⠀⠀⠀⠀⠀⠈⢪⢀⣺⡅⢈⠆⠀⠀"
		@echo "⠀⠀⠀⠀⠀⠀⠀⠶⡿⠤⠚⠁⠀⠀⠀⢀⣠⡤⢺⣥⠟⢡⠃⠀⠀⠀"
		@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀"
		@echo ""

re : fclean all
		$(info Project REBUILD!)

.PHONY: all clean fclean re
