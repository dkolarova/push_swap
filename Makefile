# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/02 11:54:03 by dkolarov          #+#    #+#              #
#    Updated: 2025/09/23 11:10:23 by dkolarov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRC_DIR	= src
OBJ_DIR	= obj
INC_DIR	= .
LIBFT_DIR	= libft
LIBFT	= $(LIBFT_DIR)/libft.a

CC	= cc
CFLAGS	= -Wall -Wextra -Werror
CPPFLAGS	= -I$(INC_DIR) -I$(LIBFT_DIR)

RM	= rm -f
RMDIR	= rm -rf

SRCS = \
	main.c \
	operations/push_operations.c \
	operations/reverse_rotate_operations.c \
	operations/rotate_operations.c \
	operations/swap_operations.c \
	parsing/input_parsing.c \
	parsing/input_validation.c \
	sorting/cost_calculation.c \
	sorting/final_positioning.c \
	sorting/movement_optimization.c \
	sorting/node_analysis.c \
	sorting/sort_main.c \
	sorting/target_finding.c \
	sorting/turk_sort.c \
	utils/memory_management.c \
	utils/stack_creation.c \
	utils/stack_utils.c

SRCS := $(addprefix $(SRC_DIR)/,$(SRCS))
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(LIBFT) -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/operations
	@mkdir -p $(OBJ_DIR)/parsing
	@mkdir -p $(OBJ_DIR)/sorting
	@mkdir -p $(OBJ_DIR)/utils

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RMDIR) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
