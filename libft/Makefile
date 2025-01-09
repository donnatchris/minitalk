# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 05:37:45 by nifromon          #+#    #+#              #
#    Updated: 2025/01/06 13:03:09 by nifromon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Arguments
NAME =				libft.a
CC = 				gcc
CFLAGS = 			-Wall -Wextra -Werror
INCLUDES =			-I $(LIBFT_H) -I $(FT_PRINTF_H) -I $(GET_NEXT_LINE_H)

# Repositories
SRCS_DIR =			src
LIBFT_SRC =			$(SRCS_DIR)/libft_SRC
FT_PRINTF_SRC = 	$(SRCS_DIR)/ft_printf_SRC
GET_NEXT_LINE_SRC =	$(SRCS_DIR)/get_next_line_SRC
HEADERS_DIR =		headers
LIBFT_H =			$(HEADERS_DIR)/libft_H/
FT_PRINTF_H =		$(HEADERS_DIR)/ft_printf_H/
GET_NEXT_LINE_H =	$(HEADERS_DIR)/get_next_line_H/
OBJS_DIR =			obj

# Utils
AR =				ar -rcs
RM =				rm -rf

# Sources and Objects
SRCS = 				\
					$(LIBFT_SRC)/ft_isalpha.c $(LIBFT_SRC)/ft_isdigit.c \
					$(LIBFT_SRC)/ft_isalnum.c $(LIBFT_SRC)/ft_isascii.c \
					$(LIBFT_SRC)/ft_isprint.c $(LIBFT_SRC)/ft_strlen.c \
					$(LIBFT_SRC)/ft_memset.c $(LIBFT_SRC)/ft_bzero.c \
					$(LIBFT_SRC)/ft_memcpy.c $(LIBFT_SRC)/ft_memmove.c \
					$(LIBFT_SRC)/ft_strlcpy.c $(LIBFT_SRC)/ft_strlcat.c \
					$(LIBFT_SRC)/ft_toupper.c $(LIBFT_SRC)/ft_tolower.c \
					$(LIBFT_SRC)/ft_strchr.c $(LIBFT_SRC)/ft_strrchr.c \
					$(LIBFT_SRC)/ft_strncmp.c $(LIBFT_SRC)/ft_memchr.c \
					$(LIBFT_SRC)/ft_memcmp.c $(LIBFT_SRC)/ft_strnstr.c \
					$(LIBFT_SRC)/ft_atoi.c $(LIBFT_SRC)/ft_calloc.c \
					$(LIBFT_SRC)/ft_strdup.c $(LIBFT_SRC)/ft_substr.c \
					$(LIBFT_SRC)/ft_strjoin.c $(LIBFT_SRC)/ft_strtrim.c \
					$(LIBFT_SRC)/ft_split.c $(LIBFT_SRC)/ft_itoa.c \
					$(LIBFT_SRC)/ft_strmapi.c $(LIBFT_SRC)/ft_striteri.c \
					$(LIBFT_SRC)/ft_putchar_fd.c $(LIBFT_SRC)/ft_putstr_fd.c \
					$(LIBFT_SRC)/ft_putendl_fd.c $(LIBFT_SRC)/ft_putnbr_fd.c \
					$(LIBFT_SRC)/ft_lstnew.c $(LIBFT_SRC)/ft_lstadd_front.c \
					$(LIBFT_SRC)/ft_lstsize.c $(LIBFT_SRC)/ft_lstlast.c \
					$(LIBFT_SRC)/ft_lstadd_back.c $(LIBFT_SRC)/ft_lstdelone.c \
					$(LIBFT_SRC)/ft_lstclear.c $(LIBFT_SRC)/ft_lstiter.c \
					$(LIBFT_SRC)/ft_lstmap.c \
					\
					$(FT_PRINTF_SRC)/ft_printf.c $(FT_PRINTF_SRC)/init.c \
					$(FT_PRINTF_SRC)/print_format_c.c $(FT_PRINTF_SRC)/check.c \
					$(FT_PRINTF_SRC)/print_format_d.c \
					$(FT_PRINTF_SRC)/print_format_i.c \
					$(FT_PRINTF_SRC)/print_format_p.c \
					$(FT_PRINTF_SRC)/print_format_s.c \
					$(FT_PRINTF_SRC)/print_format_u.c \
					$(FT_PRINTF_SRC)/print_format_x_low.c \
					$(FT_PRINTF_SRC)/print_format_x_upp.c \
					\
					$(GET_NEXT_LINE_SRC)/get_next_line.c \
					$(GET_NEXT_LINE_SRC)/get_next_line_utils.c

OBJS = 				$(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/$(SRCS_DIR)/%.o)

# Rules and Dependencies
all: 				$(NAME)

$(NAME):			$(OBJS)
					$(AR) $(NAME) $(OBJS)

$(OBJS_DIR)/$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
					@mkdir -p $(dir $@)
					$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
					$(RM) $(OBJS_DIR)

fclean: 			clean
					$(RM) $(NAME)

re: 				fclean all

.PHONY: 			all clean fclean re

#END
