# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 16:21:20 by christophed       #+#    #+#              #
#    Updated: 2025/01/03 16:19:12 by christophed      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'exécutable
SERVER_TARGET = server
CLIENT_TARGET = client
# BONUS_TARGET = NAME OF BONUS

# Répertoires
SRC_SERVER_DIR = src_server
SRC_CLIENT_DIR = src_client
UTILS_DIR = utils
OBJ_DIR = obj
OBJ_DIR_SERVER = $(OBJ_DIR)/server
OBJ_DIR_CLIENT = $(OBJ_DIR)/client
INC_DIR = includes
LIBFT_DIR = libft
# BONUS_DIR = bonus

# Fichiers source et objets
SERVER_SRCS = $(wildcard $(SRC_SERVER_DIR)/*.c) $(wildcard $(UTILS_DIR)/*.c)
CLIENT_SRCS = $(wildcard $(SRC_CLIENT_DIR)/*.c) $(wildcard $(UTILS_DIR)/*.c)

SERVER_OBJS = $(patsubst %.c, $(OBJ_DIR_SERVER)/%.o, $(notdir $(SERVER_SRCS)))
CLIENT_OBJS = $(patsubst %.c, $(OBJ_DIR_CLIENT)/%.o, $(notdir $(CLIENT_SRCS)))

# Options de compilation
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)/includes

# Spécifier le compilateur
CC = gcc

# Options de l'éditeur de liens
LDFLAGS = -L$(LIBFT_DIR) -lft

# Règles
all: $(SERVER_TARGET) $(CLIENT_TARGET)

$(OBJ_DIR_SERVER)/%.o: $(SRC_SERVER_DIR)/%.c
	mkdir -p $(OBJ_DIR_SERVER)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_CLIENT)/%.o: $(SRC_CLIENT_DIR)/%.c
	mkdir -p $(OBJ_DIR_CLIENT)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_SERVER)/%.o: $(UTILS_DIR)/%.c
	mkdir -p $(OBJ_DIR_SERVER)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_CLIENT)/%.o: $(UTILS_DIR)/%.c
	mkdir -p $(OBJ_DIR_CLIENT)
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER_TARGET): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $@ $(LDFLAGS)

$(CLIENT_TARGET): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $@ $(LDFLAGS)
    
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(SERVER_TARGET) $(CLIENT_TARGET)

re: fclean all

.PHONY: all bonus clean fclean re