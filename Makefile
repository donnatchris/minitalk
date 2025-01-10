# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 13:36:58 by nifromon          #+#    #+#              #
#    Updated: 2025/01/10 01:25:16 by christophed      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Arguments
SERVER =				server
CLIENT =				client

# Directories
SERVER_DIR =			mandatory/src/server
CLIENT_DIR =			mandatory/src/client
HEADER_DIR =			mandatory/includes

OBJ_DIR =				obj
OBJ_CLIENT_DIR =		$(OBJ_DIR)/mandatory/src/client
OBJ_SERVER_DIR =		$(OBJ_DIR)/mandatory/src/server

BONUS_CLIENT_DIR =		bonus/src/client
BONUS_SERVER_DIR =		bonus/src/server
BONUS_HEADER_DIR =		bonus/includes
OBJ_BONUS_CLIENT_DIR =	$(OBJ_DIR)/bonus/src/client
OBJ_BONUS_SERVER_DIR =	$(OBJ_DIR)/bonus/src/server

LIBFT_DIR =				libft
LIBFT =					$(LIBFT_DIR)/libft.a

# Utils
RM =					rm -rf

# Sources and objects
SERVER_SRC =			\
                        $(SERVER_DIR)/main.c $(SERVER_DIR)/receiver.c \
                        $(SERVER_DIR)/utils.c $(SERVER_DIR)/initializer.c

OBJ_SERVER_SRC =		$(SERVER_SRC:$(SERVER_DIR)/%.c=$(OBJ_SERVER_DIR)/%.o)

CLIENT_SRC =			\
                        $(CLIENT_DIR)/main.c $(CLIENT_DIR)/transmitter.c \
                        $(CLIENT_DIR)/utils.c

OBJ_CLIENT_SRC =		$(CLIENT_SRC:$(CLIENT_DIR)/%.c=$(OBJ_CLIENT_DIR)/%.o)

# Bonus sources and objects
BONUS_SERVER_SRC =		\
                        $(BONUS_SERVER_DIR)/main.c $(BONUS_SERVER_DIR)/receiver.c \
                        $(BONUS_SERVER_DIR)/utils.c $(BONUS_SERVER_DIR)/initializer.c

BONUS_OBJ_SERVER_SRC =	$(BONUS_SERVER_SRC:$(BONUS_SERVER_DIR)/%.c=$(OBJ_BONUS_SERVER_DIR)/%.o)

BONUS_CLIENT_SRC =		\
                        $(BONUS_CLIENT_DIR)/main.c $(BONUS_CLIENT_DIR)/transmitter.c \
                        $(BONUS_CLIENT_DIR)/utils.c

BONUS_OBJ_CLIENT_SRC =	$(BONUS_CLIENT_SRC:$(BONUS_CLIENT_DIR)/%.c=$(OBJ_BONUS_CLIENT_DIR)/%.o)

# Compiler and flags
CC =					gcc
CFLAGS =				-Wall -Werror -Wextra -I$(HEADER_DIR) -I$(LIBFT_DIR)/includes

# Rules and dependencies
all:					$(LIBFT) only_server only_client

bonus:					$(LIBFT) server_bonus client_bonus

$(LIBFT):
						make -C $(LIBFT_DIR) all

only_server:			$(SERVER)

$(SERVER):				$(LIBFT) $(OBJ_SERVER_SRC)
						$(CC) $(CFLAGS) $(OBJ_SERVER_SRC) $(LIBFT) -o server

only_client:			$(CLIENT)

$(CLIENT):				$(LIBFT) $(OBJ_CLIENT_SRC)
						$(CC) $(CFLAGS) $(OBJ_CLIENT_SRC) $(LIBFT) -o client

server_bonus:			$(LIBFT) $(BONUS_OBJ_SERVER_SRC)
						$(CC) $(CFLAGS) $(BONUS_OBJ_SERVER_SRC) $(LIBFT) -o server_bonus

client_bonus:			$(LIBFT) $(BONUS_OBJ_CLIENT_SRC)
						$(CC) $(CFLAGS) $(BONUS_OBJ_CLIENT_SRC) $(LIBFT) -o client_bonus

$(OBJ_SERVER_DIR)/%.o:	$(SERVER_DIR)/%.c
						@mkdir -p $(OBJ_SERVER_DIR)
						$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_CLIENT_DIR)/%.o:	$(CLIENT_DIR)/%.c
						@mkdir -p $(OBJ_CLIENT_DIR)
						$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS_SERVER_DIR)/%.o:	$(BONUS_SERVER_DIR)/%.c
						@mkdir -p $(OBJ_BONUS_SERVER_DIR)
						$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS_CLIENT_DIR)/%.o:	$(BONUS_CLIENT_DIR)/%.c
						@mkdir -p $(OBJ_BONUS_CLIENT_DIR)
						$(CC) $(CFLAGS) -c $< -o $@

clean:
						make -C $(LIBFT_DIR) clean
						$(RM) $(OBJ_DIR)

fclean:					clean
						make -C $(LIBFT_DIR) fclean
						$(RM) server client server_bonus client_bonus

re:						fclean all