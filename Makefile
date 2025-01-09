# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 13:36:58 by nifromon          #+#    #+#              #
#    Updated: 2025/01/09 09:36:52 by chdonnat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Argument
SERVER =			server
CLIENT =			client

# Compilation
CC =				gcc
CFLAGS =			-Wall -Werror -Wextra
INCLUDES =			-I $(HEADER_DIR)/

# Directories
SERVER_DIR =		server_src
CLIENT_DIR =		client_src
HEADER_DIR =		includes

OBJ_DIR =			obj
OBJ_SERVER_DIR =	$(OBJ_DIR)/server_obj
OBJ_CLIENT_DIR =	$(OBJ_DIR)/client_obj

LIBFT_DIR =			libft
LIBFT =				$(LIBFT_DIR)/libft.a

# Utils
RM =				rm -rf

# Sources and objects
SERVER_SRC =		\
					$(SERVER_DIR)/receiver.c $(SERVER_DIR)/main.c \
					$(SERVER_DIR)/initializer.c $(SERVER_DIR)/server.c


OBJ_SERVER_SRC =	$(SERVER_SRC:$(SERVER_DIR)/%.c=$(OBJ_SERVER_DIR)/%.o)

CLIENT_SRC =		\
					$(CLIENT_DIR)/client.c $(CLIENT_DIR)/main.c \
					$(CLIENT_DIR)/transmitter.c

OBJ_CLIENT_SRC =	$(CLIENT_SRC:$(CLIENT_DIR)/%.c=$(OBJ_CLIENT_DIR)/%.o)

# Rules and dependencies
all:				$(LIBFT) only_server only_client

$(LIBFT):
					make -C $(LIBFT_DIR) all

only_server:		$(SERVER)

$(SERVER):			$(LIBFT) $(OBJ_SERVER_SRC)
					$(CC) $(CFLAGS) $(OBJ_SERVER_SRC) $(LIBFT) -o $(SERVER)

$(OBJ_SERVER_DIR)/%.o: $(SERVER_DIR)/%.c
					@mkdir -p $(OBJ_DIR)
					@mkdir -p $(OBJ_SERVER_DIR)
					$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

only_client:		$(CLIENT)

$(CLIENT):			$(LIBFT) $(OBJ_CLIENT_SRC)
					$(CC) $(CFLAGS) $(OBJ_CLIENT_SRC) $(LIBFT) -o $(CLIENT)

$(OBJ_CLIENT_DIR)/%.o: $(CLIENT_DIR)/%.c
					@mkdir -p $(OBJ_DIR)
					@mkdir -p $(OBJ_CLIENT_DIR)
					$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
					make -C $(LIBFT_DIR) clean
					$(RM) $(OBJ_DIR)

fclean:				clean
					make -C $(LIBFT_DIR) fclean
					$(RM) $(SERVER) $(CLIENT)

re:					fclean all

.PHONY:				all only_server only_client clean fclean re
